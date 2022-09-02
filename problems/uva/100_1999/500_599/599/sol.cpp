#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define UNVISITED 0
#define VISITED 1
#define MAX 100000+10

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<string> vs;

int t, n, e, countVisited, lastCountVisited, visited[MAX];
int trees, acorns, nodeChars[30];
vvii adjList;
vs edges;

void dfs(int u) {
    if (visited[u] == VISITED) return;
    visited[u] = VISITED;
    countVisited++;
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
    cin >> t;
    while(t--) {
        edges = vs();
        while(true) {
            string edge;
            cin >> edge;
            if (edge[0] != '*') {
                edges.push_back(edge);
            } else {
                break;
            }
        }
        string nodes;
        cin >> nodes;
        n = (int) nodes.size() / 2 + 1;
        for (int i = 0; i < n; i++) {
            nodeChars[nodes[i << 1] - 'A'] = i;
        }
        adjList.assign(n, vii());
        for (int i = 0; i < (int) edges.size(); i++) {
            int u = nodeChars[edges[i][1] - 'A'];
            int v = nodeChars[edges[i][3] - 'A'];
            adjList[u].push_back(ii(v, 0));
            adjList[v].push_back(ii(u, 0));
        }
        trees = acorns = 0;
        countVisited = lastCountVisited = 0;
        memset(visited, UNVISITED, sizeof visited);
        for (int i = 0; i < n; i++) {
            if (visited[i] == UNVISITED) {
                dfs(i);
                if (countVisited - lastCountVisited == 1) {
                    acorns++;
                } else {
                    trees++;
                }
                lastCountVisited = countVisited;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }
    return 0;
}