#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define UNVISITED 0
#define VISITED 1
#define MAX 100000+10

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, e, visited[MAX];
vvii adjList = vvii(MAX, vii());

void dfs(int u) {
    if (visited[u] == VISITED) return;
    visited[u] = VISITED;
    int len = adjList[u].size();
    for (int i = 0; i < len; i++) {
        int v, w;
        v = adjList[u][i].first;
        w = adjList[u][i].second;
        if (visited[v] == UNVISITED) {
            dfs(v);
        }
    }
}

int main() {
    memset(visited, UNVISITED, sizeof visited);
    // your code here...
    return 0;
}