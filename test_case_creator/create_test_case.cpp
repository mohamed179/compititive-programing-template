#include <cstdio>
#include <cstdlib>
#include <time.h>

void init() {
    srand(time(0));
}

int random_integer(int lower, int upper)  {
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    init();
    int c = 1;
    while(c--) {
        int n = 10000;
        printf("%d\n", n);
        n -= 2;
        while (n--) {
            for (int i = 0; i < 4; i++) {
                printf("%d ", random_integer(100, 499));
            }
            printf("%d\n", random_integer(100, 499));
        }
    }
    printf("100 101 102 103 104\n100 101 102 103 104\n0\n");
    return 0;
}