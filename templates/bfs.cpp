#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define UNVISITED 0
#define VISITED 1
#define MAX 100000+10

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef queue<int> qi;

int n, e, visited[MAX];
vvii adjList = vvii(MAX, vii());

void bfs(int u) {
    if (visited[u] == VISITED) return;
    visited[u] = VISITED;
    qi queue = qi();
    queue.push(u);
    while(!queue.empty()) {
        u = queue.front();
        queue.pop();
        int len = adjList[u].size();
        for (int i = 0; i < len; i++) {
            int v = adjList[u][i].first;
            int w = adjList[u][i].second;
            if (visited[v] == UNVISITED) {
                visited[v] = VISITED;
                queue.push(v);
            }
        }
    }
}

int main() {
    memset(visited, UNVISITED, sizeof visited);
    // your code here...
    return 0;
}