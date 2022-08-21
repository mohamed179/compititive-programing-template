#include <cstdio>
#include <cstring>

#define MAX 1 << 14

int main() {
    int N, n, weight[MAX], potency[MAX];
    while(scanf("%d", &N) != EOF) {
        memset(weight, 0, sizeof potency);
        memset(potency, 0, sizeof potency);
        n = 1 << N;
        for (int i = 0; i < n; i++) {
            scanf("%d", &weight[i]);
        }
        for (int i = 0; i < n; i++) {
            int p = 0;
            for (int j = 0; j < N; j++) {
                potency[i] += weight[i ^ (1 << j)];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < N; j++) {
                int sum = potency[i] + potency[i ^ (1 << j)];
                ans = sum > ans ? sum : ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}