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
    int TC = 10;
    while(TC--) {
        int P = random_integer(1, 10);
        int C = 100;
        printf("%d %d\n", P, C);
        while(C--) {
            if (random_integer(1, 100) % 2) {
                printf("N\n");
            } else {
                printf("E %d\n", random_integer(1, P));
            }
        }
    }
    printf("0 0\n");
    return 0;
}