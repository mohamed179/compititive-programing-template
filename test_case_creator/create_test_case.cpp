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
    // your code here...
    return 0;
}