#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

#define UNLOAD 0
#define LOAD 1
#define MOVE 2

int t, n, s, q, cargos, process, station, ans;
queue<int> stations[110];
stack<int> carrier;

void unload();
void load();
void move();

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &s, &q);
        carrier = stack<int>();
        cargos = 0;
        process = 0;
        station = 0;
        ans = 0;
        for (int i = 0; i < n; i++) {
            stations[i] = queue<int>();
            int qi;
            scanf("%d", &qi);
            cargos += qi;
            while(qi--) {
                int cargo;
                scanf("%d", &cargo);
                stations[i].push(--cargo);
            }
        }
        while(cargos) {
            switch(process) {
                case UNLOAD:
                    unload();
                    break;
                case LOAD:
                    load();
                    break;
                case MOVE:
                    move();
                    break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

void unload() {
    while(carrier.size()) {
        int cargo = carrier.top();
        if (cargo == station) {
            carrier.pop();
            cargos--;
            ans++;
        } else if (stations[station].size() < q) {
            carrier.pop();
            stations[station].push(cargo);
            ans++;
        } else {
            break;
        }
    }
    process = LOAD;
}

void load() {
    while(stations[station].size()) {
        int cargo = stations[station].front();
        if (carrier.size() < s) {
            stations[station].pop();
            carrier.push(cargo);
            ans++;
        } else {
            break;
        }
    }
    process = MOVE;
}

void move() {
    ans += 2;
    station = (station + 1) % n;
    process = UNLOAD;
}