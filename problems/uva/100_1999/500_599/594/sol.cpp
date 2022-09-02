#include <cstdio>
#include <bitset>
using namespace std;

int main() {
    int x;
    while(scanf("%d", &x) != EOF) {
        bitset<8> bytes[5];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                bytes[i][j] = (x & (1 << (8 * i + j))) ? 1 : 0;
            }
        }
        int ans = 0;
        for (int i = 3; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                ans |= bytes[i][j] << (8 * (3 - i) + j);
            }
        }
        printf("%d converts to %d\n", x, ans);
    }
    return 0;
}