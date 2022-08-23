#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define LEFT 0
#define RIGHT 1

typedef queue<int> qi;

int c, l, m;
int ans, available, position;
qi left, right;

void doLoad();
void doMove();
void doUnload();

int main() {
    scanf("%d", &c);
    while(c--) {
        scanf("%d %d", &l, &m);
        l *= 100;
        ans = 0;
        available = l;
        position = LEFT;
        right = qi();
        left = qi();
        for (int i = 0; i < m; i++) {
            int length;
            char pos[10];
            scanf("%d %s", &length, pos);
            if (!strcmp(pos, "left")) {
                left.push(length);
            } else {
                right.push(length);
            }
        }
        while(!left.empty() || !right.empty()) {
            doLoad();
            doMove();
            doUnload();
        }
        printf("%d\n", ans);
    }
    return 0;
}

void doLoad() {
    qi *current = position == LEFT ? &left : &right;
    while(!current->empty()) {
        int car = current->front();
        if (available >= car) {
            current->pop();
            available -= car;
        } else {
            break;
        }
    }
}

void doMove() {
    ans++;
    position = position == LEFT ? RIGHT : LEFT;
}

void doUnload() {
    available = l;
}