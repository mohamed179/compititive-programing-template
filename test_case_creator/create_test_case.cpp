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
    int TC = 100;
    while(TC--) {
        int n = random_integer(1, 50);
        printf("%d\n", n);
        printf("%lld", random_ll_integer(1, 1 << 30));
        n--;
        while(n--) {
            printf(" %d", random_integer(1, 1 << 30));
        }
        printf("\n");
    }
    printf("0\n");
    return 0;
}