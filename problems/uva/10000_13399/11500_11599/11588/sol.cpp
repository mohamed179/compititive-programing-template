#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, char> ic;
typedef vector<ic> vic;

int main() {
    int X;
    scanf("%d", &X);
    for (int TC = 1; TC <= X; TC++) {
        int R, C, M, N;
        scanf("%d %d %d %d", &R, &C, &M, &N);
        vic regions = vic();
        for (char c = 'A'; c <= 'Z'; c++) {
            regions.push_back(ic(0, c));
        }
        for (int i = 0; i < R; i++) {
            char column[25];
            scanf("%s", column);
            for (int j = 0; j < C; j++) {
                regions[column[j] - 'A'].first++;
            }
        }
        sort(regions.begin(), regions.end());
        int maxRegionSize = regions[(int) regions.size() - 1].first;
        int ans = 0;
        for (int i = 0; i < (int) regions.size(); i++) {
            ic region = regions[i];
            ans += region.first == maxRegionSize ?
                   region.first * M :
                   region.first * N;
        }
        printf("Case %d: %d\n", TC, ans);
    }
    return 0;
}