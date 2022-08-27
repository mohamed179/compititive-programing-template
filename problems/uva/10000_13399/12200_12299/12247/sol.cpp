#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define UNUSED 0
#define USED 1

int main() {
    int princess[5];
    int prince[5];
    int used[55];
    while (true) {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        if (!a && !b && !c && !d && !e) {
            break;
        }
        memset(used, UNUSED, sizeof used);
        used[a] = used[b] = used[c] = used[d] = used[e] = USED;
        princess[0] = a;
        princess[1] = b;
        princess[2] = c;
        sort(princess, princess + 3);
        prince[0] = d;
        prince[1] = e;
        sort(prince, prince + 2);
        if (princess[2] > prince[1] && princess[1] > prince[0]) {
            printf("-1\n");
            continue;
        }
        int thirdCard = 
            princess[2] < prince[0] ? 0 :
            princess[1] > prince[0] ? princess[2] :
            princess[1];
        int idx = -1;
        for (int i = 1; i <= 52; i++) {
            if (used[i] == UNUSED && i > thirdCard) {
                idx = i;
                break;
            }
        }
        printf("%d\n", idx);
    }
    return 0;
}