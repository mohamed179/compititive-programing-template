#include <cstdio>

int main() {
    int t, n = 52;
    char cards[60][5];
    scanf("%d", &t);
    for (int TC = 1; TC <= t; TC++) {
        for (int i = n - 1; i >= 0; i--) {
            scanf("%s", cards[i]);
        }
        int idx = 25, y = 0;
        for (int i = 0; i < 3; i++) {
            int value = cards[idx][0] >= '2' && cards[idx][0] <= '9' ? cards[idx][0] - '0' : 10;
            y += value;
            idx += 11 - value;
        }
        if ((n - y) >= idx) {
            printf("Case %d: %s\n", TC, cards[n - y]);
        } else {
            printf("Case %d: %s\n", TC, cards[25 - (y - (n - idx))]);
        }
    }
    return 0;
}