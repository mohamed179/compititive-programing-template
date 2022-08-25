#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vi snowflakes = vi(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &snowflakes[i]);
        }
        mii firstOf = mii();
        int ans = 0;
        int current = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int sf = snowflakes[i];
            if (firstOf.find(sf) == firstOf.end() || firstOf[sf] < start || firstOf[sf] == i) {
                firstOf[sf] = i;
                current++;
                ans = current > ans ? current : ans;
            } else {
                i = firstOf[sf];
                start = i + 1;
                current = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}