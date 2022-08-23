#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define LEFT 0
#define RIGHT 1
#define INF 1000000000

typedef pair<int, int> ii;
typedef queue<ii> qii;

int c, n, t, m;
int now, position, ans[10010];
qii ferry, left, right;

void doLoad();
void doMove();
void doUnload();
void doWait();

int main() {
    scanf("%d", &c);
    for (int TC = 0; TC < c; TC++) {
        if (TC) printf("\n");
        scanf("%d %d %d", &n, &t, &m);
        memset(ans, 0, sizeof ans);
        left = qii();
        right = qii();
        now = 0;
        position = LEFT;
        for (int i = 0; i < m; i++) {
            int arrive;
            char dir[10];
            scanf("%d %s", &arrive, dir);
            if (!strcmp(dir, "left")) {
                left.push(ii(arrive, i));
            } else {
                right.push(ii(arrive, i));
            }
        }
        while(left.size() || right.size()) {
            ii carAtLeft = left.size() ? left.front() : ii(INF, -1);
            ii carAtRight = right.size() ? right.front() : ii(INF, -1);
            if (now >= carAtLeft.first && position == LEFT) {
                doLoad();
                doMove();
                doUnload();
            } else if (now >= carAtRight.first && position == RIGHT) {
                doLoad();
                doMove();
                doUnload();
            } else if (now >= carAtLeft.first && position == RIGHT) {
                doMove();
            } else if (now >= carAtRight.first && position == LEFT) {
                doMove();
            } else {
                doWait();
            }
        }
        for (int i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

void doLoad() {
    qii *current = position == LEFT ? &left : &right;
    while ((int) ferry.size() < n && current->size()) {
        ii car = current->front();
        if (now >= car.first) {
            current->pop();
            ferry.push(car);
        } else {
            break;
        }
    }
}

void doMove() {
    now += t;
    position = position == LEFT ? RIGHT : LEFT;
}

void doUnload() {
    while(ferry.size()) {
        ii car = ferry.front();
        ferry.pop();
        ans[car.second] = now;
    }
}

void doWait() {
    ii carAtLeft = left.size() ? left.front() : ii(INF, -1);
    ii carAtRight = right.size() ? right.front() : ii(INF, -1);
    now = carAtLeft < carAtRight ? carAtLeft.first : carAtRight.first;
}