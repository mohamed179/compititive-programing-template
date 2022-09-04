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
    char departments[110][5];
    int counter = 0;
    for (int i = 0; i < 26 && counter < 100; i++) {
        for (int j = 0; j < 26 && counter < 100; j++) {
            for (int k = 0; k < 26 && counter < 100; k++) {
                departments[counter][0] = 'A' + i;
                departments[counter][1] = 'A' + j;
                departments[counter][2] = 'A' + k;
                departments[counter][3] = '\0';
                counter++;
            }
        }
    }
    char strings[1010][5];
    counter = 0;
    for (int i = 0; i < 26 && counter < 1000; i++) {
        for (int j = 0; j < 26 && counter < 1000; j++) {
            for (int k = 0; k < 26 && counter < 1000; k++) {
                strings[counter][0] = 'a' + i;
                strings[counter][1] = 'a' + j;
                strings[counter][2] = 'a' + k;
                strings[counter][3] = '\0';
                counter++;
            }
        }
    }
    int n = random_integer(2, 12);
    printf("%d\n", n);
    while(n--) {
        printf("%s\n", departments[random_integer(0, 99)]);
        int m = random_integer(1, 20);
        while(m--) {
            int tt = random_integer(0, 999);
            int fn = random_integer(0, 999);
            int ln = random_integer(0, 999);
            int add = random_integer(0, 999);
            int hp = random_integer(0, 999);
            int wp = random_integer(0, 999);
            int cb = random_integer(0, 999);
            printf("%s,%s,%s,%s,%s,%s,%s\n", 
                strings[tt],
                strings[fn],
                strings[ln],
                strings[add],
                strings[hp],
                strings[wp],
                strings[cb]);
        }
        if (n) printf("\n");
    }
    return 0;
}