#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

class Computer {
public:
    int idx, current, interval;
    Computer(int idx, int current, int start, int end) {
        this->idx = idx;
        this->current = current;
        this->interval = end - start;
    }
    friend bool operator< (Computer const c1, Computer const c2);
    friend bool operator== (Computer const c1, Computer const c2);
    friend bool operator!= (Computer const c1, Computer const c2);
    friend bool operator> (Computer const c1, Computer const c2);
    void next() {
        this->current += this->interval;
    }
};

bool operator< (Computer const c1, Computer const c2) {
    return c1.current < c2.current;
}
bool operator== (Computer const c1, Computer const c2) {
    return c1.current == c2.current;
}
bool operator!= (Computer const c1, Computer const c2) {
    return c1.current != c2.current;
}
bool operator> (Computer const c1, Computer const c2) {
    return c1.current > c2.current;
}

int main() {
    for (int TC = 1; ; TC++) {
        int n;
        scanf("%d", &n);
        if (!n) break;
        vector<Computer> computers = vector<Computer>();
        priority_queue<Computer, vector<Computer>, greater<vector<Computer>::value_type>> pq;
        pq = priority_queue<Computer, vector<Computer>, greater<vector<Computer>::value_type>>();
        for (int i = 0; i < n; i++) {
            int y, a, b;
            scanf("%d %d %d", &y, &a, &b);
            Computer computer = Computer(i, y, a, b);
            computers.push_back(computer);
            pq.push(computer);
        }
        bool done = false;
        bool found = false;
        while(true) {
            done = true;
            found = true;
            for (int i = 0; i < n; i++) {
                if (computers[i].current >= 10000) {
                    done = true;
                    found = false;
                    break;
                }
                if (i < n - 1 && computers[i] != computers[i + 1]) {
                    done = false;
                    continue;
                }
            }
            if (done) break;
            Computer computer = pq.top();
            pq.pop();
            computer.next();
            computers[computer.idx].next();
            pq.push(computer);
        }
        if (found) {
            printf("Case #%d:\nThe actual year is %d.\n\n", TC, computers[0].current);
        } else {
            printf("Case #%d:\nUnknown bugs detected.\n\n", TC);
        }
    }
    return 0;
}