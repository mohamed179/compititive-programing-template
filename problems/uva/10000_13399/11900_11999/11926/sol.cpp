#include <cstdio>
#include <bitset>
using namespace std;

#define MAX 1000000

int main() {
    int n, m;
    bitset<MAX+10> bitmask;
    while (scanf("%d %d", &n, &m) && (n || m)) {
        bitmask.reset();
        bool conflict = false;
        for (int i = 0; i < n; i++) {
            int start, end;
            scanf("%d %d", &start, &end);
            if (!conflict) {
                for (int t = start; t <= MAX && t < end; t++) {
                    if (bitmask.test(t)) conflict = true;
                    else bitmask[t] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int start, end, interval;
            scanf("%d %d %d", &start, &end, &interval);
            while(start < MAX && !conflict) {
                if (!conflict) {
                    for (int t = start; t <= MAX && t < end; t++) {
                        if (bitmask.test(t)) conflict = true;
                        else bitmask[t] = 1;
                    }
                }
                start += interval;
                end += interval;
            }
        }
        printf(conflict ? "CONFLICT\n" : "NO CONFLICT\n");
    }
    return 0;
}