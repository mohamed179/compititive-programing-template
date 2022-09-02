#include <cstdio>

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

int main() {
    int n;
    long long int p;
    while (scanf("%d %lld", &n, &p) && n && p) {
        int deltaX = 0, deltaY = 0, direction = UP;
        long long int spiral = 1;
        int i = n / 2 + 1, j = n / 2 + 1;
        bool found = p == 1 ? true : false;
        while(!found) {
            switch(direction) {
                case UP:
                    deltaY++;
                    spiral += deltaY;
                    i += deltaY;
                    if (spiral >= p) {
                        found = true;
                        i -= spiral - p;
                    }
                    break;
                case LEFT:
                    deltaX++;
                    spiral += deltaX;
                    j -= deltaX;
                    if (spiral >= p) {
                        found = true;
                        j += spiral - p;
                    }
                    break;
                case DOWN:
                    deltaY++;
                    spiral += deltaY;
                    i -= deltaY;
                    if (spiral >= p) {
                        found = true;
                        i += spiral - p;
                    }
                    break;
                case RIGHT:
                    deltaX++;
                    spiral += deltaX;
                    j += deltaX;
                    if (spiral >= p) {
                        found = true;
                        j -= spiral - p;
                    }
                    break;
            }
            direction = (direction + 1) % 4;
        }
        printf("Line = %d, column = %d.\n", i, j);
    }
    return 0;
}