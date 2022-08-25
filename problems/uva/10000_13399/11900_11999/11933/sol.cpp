#include <cstdio>

int main() {
    unsigned int n;
    while(scanf("%u", &n) && n) {
        unsigned int a = 0, b = 0;
        int aOrB = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                if (aOrB % 2) b |= 1 << i;
                else a |= 1 << i;
                aOrB++;
            }
        }
        printf("%u %u\n", a, b);
    }
    return 0;
}