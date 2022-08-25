#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef map<int, int> mii;

ii uniqueElementsLongestRange(int n, vi elements) {
    int start, current, max;
    start = current = max = 0;
    mii firsIdxOf = mii();
    ii ans;
    for (int i = 0; i < n; i++) {
        int x = elements[i];
        if (firsIdxOf.find(x) == firsIdxOf.end() || firsIdxOf[x] < start || firsIdxOf[x] == i) {
            firsIdxOf[x] = i;
            current++;
            if (current > max) {
                max = current;
                ans = ii(start, i);
            }
        } else {
            i = firsIdxOf[x];
            start = i + 1;
            current = 0;
        }
    }
    return ans;
}

int main() {
    // your code here...
    return 0;
}