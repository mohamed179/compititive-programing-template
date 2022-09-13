#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define BLUE 0
#define RED 1

typedef vector<int> vi;

int calculate(int i, int j, int next, vi *blues, vi *reds);

int main() {
    int p;
    scanf("%d", &p);
    while(p--) {
        int n;
        scanf("%d", &n);
        vi blues = vi(), reds = vi();
        for (int i = 0; i < n; i++) {
            int floor;
            scanf("%d", &floor);
            if (floor > 0) blues.push_back(floor);
            else reds.push_back(-floor);
        }
        sort(blues.begin(), blues.end());
        sort(reds.begin(), reds.end());
        int ans;
        if ((int) blues.size() == 0 && (int) reds.size() == 0) {
            ans = 0;
        } else if ((int) blues.size() == 0 || (int) reds.size() == 0) {
            ans = 1;
        } else {
            int proposal1 = 1 + calculate((int) blues.size() - 1, (int) reds.size() - 1, BLUE, &blues, &reds);
            int proposal2 = 1 + calculate((int) blues.size() - 1, (int) reds.size() - 1, RED, &blues, &reds);
            ans = proposal1 > proposal2 ? proposal1 : proposal2;
        }
        printf("%d\n", ans);
    }
    return 0;
}

int calculate(int i, int j, int next, vi *blues, vi *reds) {
    int ans = 0;
    switch(next) {
        case BLUE:
            for (int ii = i; ii >= 0; ii--) {
                if (blues->at(ii) < reds->at(j)) {
                    ans = 1 + calculate(ii, j - 1, RED, blues, reds);
                    break;
                }
            }
            break;
        case RED:
            for (int jj = j; jj >= 0; jj--) {
                if (reds->at(jj) < blues->at(i)) {
                    ans = 1 + calculate(i - 1, jj, BLUE, blues, reds);
                    break;
                }
            }
            break;
        default:
            break;
    }
    return ans;
}