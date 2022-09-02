#include <cstdio>
#include <set>
using namespace std;

typedef pair<int, int> ii;
typedef set<ii> sii;

int main() {
    int t, n, m;
    int matrix[50][50];
    sii edgeList; 
    scanf("%d", &t);
    while(t--) {
        edgeList = sii();
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        bool yes = true;
        for (int j = 0; j < m && yes; j++) {
            int count = 0;
            ii edge;
            for (int i = 0; i < n && yes; i++) {
                if (matrix[i][j]) {
                    count++;
                    if (count == 1) edge.first = i;
                    else if (count == 2) edge.second = i;
                    else yes = false;
                }
            }
            if (count < 2) yes = false;
            if (edgeList.find(edge) == edgeList.end()) {
                edgeList.insert(edge);
            } else {
                yes = false;
            }
        }
        printf(yes ? "Yes\n" : "No\n");
    }
    return 0;
}