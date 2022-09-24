#include <cstdio>
#include <queue>
#include <set>
using namespace std;

typedef queue<int> qi;
typedef multiset<int> si;

int main() {
    int K;
    scanf("%d", &K);
    for (int TC = 0; TC < K; TC++) {
        int M, N;
        scanf("%d %d", &M, &N);
        qi addings = qi();
        qi gettings = qi();
        for (int i = 0; i < M; i++) {
            int x;
            scanf("%d", &x);
            addings.push(x);
        }
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            gettings.push(x);
        }
        si sorted = si();
        int idx = 0;
        if (TC) printf("\n");
        while(!gettings.empty()) {
            if (gettings.front() == (int) sorted.size()) {
                gettings.pop();
                si::iterator it = sorted.begin();
                advance(it, idx);
                idx++;
                printf("%d\n", *it);
            } else {
                sorted.insert(addings.front());
                addings.pop();
            }
        }
    }
    return 0;
}