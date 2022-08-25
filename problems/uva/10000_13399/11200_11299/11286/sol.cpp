#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, max, ans;
    vvi froshes;
    map<vi, int> popularities;
    while(scanf("%d", &n) && n) {
        froshes = vvi();
        popularities = map<vi, int>();
        max = ans = 0;
        for (int i = 0; i < n; i++) {
            vi combination = vi(5);
            for (int j = 0; j < 5; j++) {
                scanf("%d", &combination[j]);
            }
            sort(combination.begin(), combination.end());
            froshes.push_back(combination);
            if (popularities.find(combination) == popularities.end()) {
                popularities[combination] = 1;
            } else {
                popularities[combination]++;
            }
            max = popularities[combination] > max ? popularities[combination] : max;
        }
        for (int i = 0; i < n; i++) {
            vi combination = froshes[i];
            if (popularities[combination] == max) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}