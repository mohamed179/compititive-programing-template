#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

bool compareFn(ii const num1, ii const num2);

int main() {
    int n, m;
    vii nums;
    while(true) {
        scanf("%d %d", &n, &m);
        printf("%d %d\n", n, m);
        if (!n && !m) break;
        nums = vii(n, ii(0, 0));
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i].first);
            nums[i].second = nums[i].first % m;
        }
        sort(nums.begin(), nums.end(), compareFn);
        for (int i = 0; i < n; i++) {
            printf("%d\n", nums[i].first);
        }
    }
    return 0;
}

bool compareFn(ii const num1, ii const num2) {
    if (num1.second < num2.second) {
        return true;
    } else if (num1.second == num2.second) {
        if (num1.first % 2 == 1 && num2.first % 2 == 0) {
            return true;
        } else if (num1.first % 2 == -1 && num2.first % 2 == 0) {
            return true;
        } else if (num1.first % 2 == 0 && num2.first % 2 == 1) {
            return false;
        } else if (num1.first % 2 == 0 && num2.first % 2 == -1) {
            return false;
        } else if (num1.first % 2 == 1 || num1.first % 2 == -1) {
            return num1.first > num2.first;
        } else {
            return num1.first < num2.first;
        }
    }
    return false;
}