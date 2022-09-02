#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int p;
        scanf("%d", &p);
        vvii adjList = vvii(p + 5, vii());
        int min = 10000;
        vi ans = vi();
        for (int u = 1; u <= p; u++) {
            int v;
            do {
                scanf("%d", &v);
                adjList[u].push_back(ii(v, 0));
            } while(getchar() != '\n');
            if ((int) adjList[u].size() < min) {
                min = (int) adjList[u].size();
                ans = vi();
                ans.push_back(u);
            } else if ((int) adjList[u].size() == min) {
                ans.push_back(u);
            }
        }
        for (int i = 0; i < (int) ans.size() - 1; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[(int) ans.size() - 1]);
        if (N) getchar();
    }
    return 0;
}