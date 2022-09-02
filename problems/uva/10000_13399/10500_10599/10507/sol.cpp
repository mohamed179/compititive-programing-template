#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define INF 1000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<char ,int> mci;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int m;
        scanf("%d", &m);
        vvi adjList = vvi(n, vi());
        vi wakedup = vi(n, 0);
        mci graphIdx = mci();
        char conection[5];
        scanf("%s", conection);
        for (int i = 0; i < 3; i++) {
            graphIdx[conection[i]] = i;
            wakedup[i] = INF;
        }
        for (int i = 0; i < m; i++) {
            scanf("%s", conection);
            for (int j = 0; j < 2; j++) {
                if (graphIdx.find(conection[j]) == graphIdx.end()) {
                    int idx = (int) graphIdx.size();
                    graphIdx[conection[j]] = idx;
                }
            }
            int u = graphIdx[conection[0]];
            int v = graphIdx[conection[1]];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            if (wakedup[u] == INF) {
                wakedup[v]+= wakedup[v] < INF ? 1 : 0;
            }
            if (wakedup[v] == INF) {
                wakedup[u]+= wakedup[u] < INF ? 1 : 0;
            }
        }
        int ans = 0;
        bool willWakeUp = true;
        while(true) {
            int has_less_than_3_connections = 0;
            int has_more_than_2_connections = 0;
            for (int u = 0; u < n; u++) {
                if (wakedup[u] < 3) {
                    has_less_than_3_connections++;
                } else if (wakedup[u] < INF) {
                    has_more_than_2_connections++;
                    wakedup[u] = INF;
                } else {
                    wakedup[u]++;
                }
            }
            if (has_less_than_3_connections && !has_more_than_2_connections) {
                willWakeUp = false;
                break;
            } else if (!has_more_than_2_connections) {
                break;
            } else {
                ans++;
                for (int u = 0; u < n; u++) {
                    if (wakedup[u] == INF) {
                        int len = (int) adjList[u].size();
                        for (int i = 0; i < len; i++) {
                            int v = adjList[u][i];
                            if (wakedup[v] < INF) wakedup[v]++;
                        }
                    }
                }
            }
        }
        if (willWakeUp) printf("WAKE UP IN, %d, YEARS\n", ans);
        else printf("THIS BRAIN NEVER WAKES UP\n");
    }
    return 0;
}