#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef map<int, int> mii;

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        vvvii graphs = vvvii();
        mii graphIdx = mii();
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (graphIdx.find(x) == graphIdx.end()) {
                graphs.push_back(vvii());
                graphIdx[x] = graphs.size() - 1;
                graphs[graphIdx[x]].push_back(vii());
            }
            int idx = graphIdx[x];
            int lastNodeIdx = graphs[idx].size() - 1;
            graphs[idx].push_back(vii());
            graphs[idx][lastNodeIdx].push_back(ii(lastNodeIdx + 1, i));
        }
        for (int i = 0; i < m; i++) {
            int k, v;
            scanf("%d %d", &k, &v);
            int ans = 0;
            if (graphIdx.find(v) != graphIdx.end()) {
                int idx = graphIdx[v];
                if (graphs[idx].size() > k) {
                    ans = graphs[idx][k - 1][0].second + 1;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}