#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ABS(A) ((A) > 0 ? (A) : (-(A)))

typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int S, A, F;
        scanf("%d %d %d", &S, &A, &F);
        vi pointsX = vi();
        vi pointsY = vi();
        for (int i = 0; i < F; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            pointsX.push_back(x);
            pointsY.push_back(y);
        }
        sort(pointsX.begin(), pointsX.end());
        sort(pointsY.begin(), pointsY.end());
        ii ans;
        ans.first = pointsX[((int) pointsX.size() - 1) / 2];
        ans.second = pointsY[((int) pointsY.size() - 1) / 2];
        printf("(Street: %d, Avenue: %d)\n", ans.first, ans.second);
    }
    return 0;
}