#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii>vvvii;

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF) {
        // Get the inputs...
        vvvii matrix = vvvii(m, vvii());
        vvi rows = vvi(m, vi());
        vi nextColumns = vi(m, n);
        for (int i = 0; i < m; i++) {
            int r;
            scanf("%d", &r);
            vi columns = vi(r, -1);
            for (int j = 0; j < r; j++) {
                scanf("%d", &columns[j]);
            }
            for (int j = 0; j < r; j++) {
                int value;
                scanf("%d", &value);
                rows[i].push_back(value);
                if (j == 0) {
                    nextColumns[i] = columns[0] - 1;
                    matrix[i].push_back(vii());
                } else {
                    int prevColumn = columns[j - 1];
                    int column = columns[j];
                    matrix[i].push_back(vii());
                    matrix[i][(int) rows[i].size() - 2].push_back(ii((int) rows[i].size() - 1, column - prevColumn -1));
                }
            }
        }

        // Print the transpose matrix...
        vi matrixIdx = vi(m, 0);
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++) {
            int r = 0;
            vi columns = vi();
            vi values = vi();
            for (int j = 0; j < m; j++) {
                if (nextColumns[j] == i) {
                    r++;
                    columns.push_back(j + 1);
                    values.push_back(rows[j][matrixIdx[j]]);
                    if ((int) matrix[j][matrixIdx[j]].size() > 0) {
                        int zeros = matrix[j][matrixIdx[j]][0].second;
                        nextColumns[j] += zeros + 1;
                    }
                    matrixIdx[j]++;
                }
            }
            printf("%d", r);
            for (int j = 0; j < r; j++) printf(" %d", columns[j]);
            printf("\n");
            if (r > 0) printf("%d", values[0]);
            for (int j = 1; j < r; j++) printf(" %d", values[j]);
            printf("\n");
        }
    }
    return 0;
}