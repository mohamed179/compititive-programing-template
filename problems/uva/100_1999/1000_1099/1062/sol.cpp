#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1000

int main() {
    int n;
    char containers[MAX + 10];
    vector<stack<char>> stacks;
    for (int t = 1; true;t++) {
        scanf("%s", containers);
        if (!strcmp(containers, "end")) break;
        n = strlen(containers);
        stacks.clear();
        for (int i = 0; i < n; i++) {
            int m = (int) stacks.size();
            bool stacked = false;
            for (int j = 0; j < m; j++) {
                if (stacks[j].top() >= containers[i]) {
                    stacked = true;
                    stacks[j].push(containers[i]);
                    break;
                }
            }
            if (!stacked) {
                stack<char> newStack;
                newStack.push(containers[i]);
                stacks.push_back(newStack);
            }
        }
        printf("Case %d: %d\n", t, (int) stacks.size());
    }
    return 0;
}