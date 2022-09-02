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
    int TC = 10;
    char teams[30][20];
    int t = random_integer(1, 28);
    int g = random_integer(0, 100);
    while(TC--) {
        t = random_integer(1, 28);
        g = random_integer(0, 100);
        printf("%d %d\n", t, g);
        for (int i = 0; i < t; i++) {
            int teamLen = random_integer(1, 15);
            for (int j = 0; j < teamLen; j++) {
                if (random_integer(1, 2) % 2) {
                    teams[i][j] = 'a' + random_integer(0, 25);
                } else {
                    teams[i][j] = 'A' + random_integer(0, 25);
                }
            }
            teams[i][teamLen] = '\0';
            printf("%s\n", teams[i]);
        }
        for (int i = 0; i < g; i++) {
            int home = random_integer(0, t - 1);
            int homeScore = random_integer(0, 10);
            int away = random_integer(0, t - 1);
            while(away == home) away = random_integer(0, t - 1);
            int awayScore = random_integer(0, 10);
            printf("%s %d - %d %s\n", teams[home], homeScore, awayScore, teams[away]);
        }
    }
    printf("0 0\n");
    return 0;
}