#include <bits/stdc++.h>
using namespace std;

void init() {
    srand(time(0));
}

int random_integer(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

long long int random_ll_integer(long long int lower, long long int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    init();
    int TC = 1;
    printf("%d\n", TC);
    while(TC--) {
        printf("\n");
        int M = 30000;
        int N = 30000;
        printf("%d %d\n", M, N);
        while(M--) {
            bool pos = random_integer(0, 1);
            int num = random_integer(0, 2000000000);
            if (!pos) num = -num;
            printf("%d ", num);
        }
        printf("\n");
        for (int i = 1; i <= N; i++) printf("%d ", i);
        printf("\n");
    }
    return 0;
}