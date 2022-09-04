#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for (int TC = 1; TC <= N; TC++) {
        int C, R;
        scanf("%d %d", &C, &R);
        if (C == R) {
            printf("Case #%d: 0\n", TC);
        } else if (R > C) {
            printf("Case #%d:\n", TC);
        } else {
            int num = C - R;
            int sqt = sqrt(num);
            set<int> ans = set<int>();
            for (int i = 1; i <= sqt; i++) {
                if (num % i == 0) {
                    if (i > R) ans.insert(i);
                    if ((num / i) > R) ans.insert(num / i);
                }
            }
            printf("Case #%d:", TC);
            for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
                printf(" %d", *it);
            }
            printf("\n");
        }
    }
    return 0;
}