#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define NOTOCCUPIED 0
#define OCCUPIED 1
#define UNVISITED 0
#define VISITED 1

typedef pair<int, int> ii;
typedef pair<char, ii> cii;
typedef map<cii, int> mciii;

int t, n, m, ans, board[15][15], visited[15][15];
char piece;
mciii memo = mciii();

void findRock(int i, int j, int current);
void findKnight(int i, int j, int current);
// void findQueen(int i, int j, int current);
// void findKing(int i, int j, int current);

int main() {
    scanf("%d", &t);
    while(t--) {
        memset(board, NOTOCCUPIED, sizeof board);
        memset(visited, UNVISITED, sizeof visited);
        scanf("\n%c %d %d", &piece, &m, &n);
        if (memo.find(cii(piece, ii(m, n))) != memo.end()) {
            ans = memo[cii(piece, ii(m, n))];
        } else if (memo.find(cii(piece, ii(n, m))) != memo.end()) {
            ans = memo[cii(piece, ii(m, n))] = memo[cii(piece, ii(n, m))];
        } else {
            ans = 0;
            switch(piece) {
                case 'r':
                    findRock(0, 0, 0);
                    memo[cii(piece, ii(m, n))] = ans;
                    break;
                case 'k':
                    findKnight(0, 0, 0);
                    memo[cii(piece, ii(m, n))] = ans;
                    break;
                // case 'Q':
                //     findQueen(0, 0, 0);
                //     memo[cii(piece, ii(m, n))] = ans;
                //     break;
                // case 'K':
                //     findKing(0, 0, 0);
                //     memo[cii(piece, ii(m, n))] = ans;
                //     break;
                default:
                    break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

void findRock(int i, int j, int current) {
    ans = current > ans ? current : ans;
    if (i >= m || j >= n) return;
    bool oneInRow = false;
    bool oneInColumn = false;
    for (int ii = 0; ii < i; ii++) {
        if (board[ii][j] == OCCUPIED) {
            oneInColumn = true;
            break;
        }
    }
    for (int jj = 0; jj < j && !oneInColumn; jj++) {
        if (board[i][jj] == OCCUPIED) {
            oneInRow = true;
            break;
        }
    }
    if (!oneInRow && !oneInColumn) {
        board[i][j] = OCCUPIED;
        findRock(i + 1, j + 1, current + 1);
        board[i][j] = NOTOCCUPIED;
    }
    findRock(i, j + 1, current);
    findRock(i + 1, j, current);
}

void findKnight(int i, int j, int current) {
    if (i >= m || j >= n) {
        ans = current > ans ? current : ans;
        return;
    }
    visited[i][j] = VISITED;
    if ((i - 2 < 0  || j - 1 < 0  || board[i - 2][j - 1] == NOTOCCUPIED) &&
        (i - 2 < 0  || j + 1 >= n || board[i - 2][j + 1] == NOTOCCUPIED) &&
        (i + 2 >= m || j - 1 < 0  || board[i + 2][j - 1] == NOTOCCUPIED) &&
        (i + 2 >= m || j + 1 >= n || board[i + 2][j + 1] == NOTOCCUPIED) &&
        (i - 1 < 0  || j - 2 < 0  || board[i - 1][j - 2] == NOTOCCUPIED) &&
        (i + 1 >= m || j - 2 < 0  || board[i + 1][j - 2] == NOTOCCUPIED) &&
        (i - 1 < 0  || j + 2 >= n || board[i - 1][j + 2] == NOTOCCUPIED) &&
        (i + 1 >= m || j + 1 >= n || board[i + 1][j + 2] == NOTOCCUPIED)) {
        board[i][j] = OCCUPIED;
        if (i + 1 >= m || visited[i + 1][j] == UNVISITED) findKnight(i + 1, j, current + 1);
        if (j + 1 >= n || visited[i][j + 1] == UNVISITED) findKnight(i, j + 1, current + 1);
        if (i - 1 > 0  && visited[i - 1][j] == UNVISITED) findKnight(i - 1, j, current + 1);
        if (j - 1 > 0  && visited[i][j - 1] == UNVISITED) findKnight(i, j - 1, current + 1);
        board[i][j] = NOTOCCUPIED;
    }
    if (i + 1 >= m || visited[i + 1][j] == UNVISITED) findKnight(i + 1, j, current);
    if (j + 1 >= n || visited[i][j + 1] == UNVISITED) findKnight(i, j + 1, current);
    if (i - 1 >= 0 && visited[i - 1][j] == UNVISITED) findKnight(i - 1, j, current);
    if (j - 1 >= 0 && visited[i][j - 1] == UNVISITED) findKnight(i, j - 1, current);
    visited[i][j] = UNVISITED;
}