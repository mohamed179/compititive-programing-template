#include <cstdio>
#include <cstdlib>
#include <time.h>

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
    int t = 1;
    while(t--) {
        int n = 100000;
        while(n--) {
            switch(random_integer(1, 100) % 27) {
                case 0:
                    printf("[");
                    break;
                case 1:
                    printf("]");
                    break;
                default:
                    printf("%c", 'a' + random_integer(0, 25));
            }
        }
        printf("\n");
    }
    return 0;
}