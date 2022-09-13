#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    for (int TC = 1; ; TC++) {
        int P, C;
        scanf("%d %d", &P, &C);
        if (!P && !C) break;
        deque<int> dq = deque<int>();
        for (int i = 1; i <= 1000 && i <= P; i++) {
            dq.push_back(i);
        }
        printf("Case %d:\n", TC);
        while(C--) {
            char command[5];
            scanf("%s", command);
            if (strcmp(command, "N") == 0) {
                int top = dq.front();
                dq.pop_front();
                dq.push_back(top);
                printf("%d\n", top);
            } else {
                int x;
                scanf("%d", &x);
                for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
                    if (*it == x) {
                        dq.erase(it);
                        break;
                    }
                }
                dq.push_front(x);
            }
        }
    }
    return 0;
}