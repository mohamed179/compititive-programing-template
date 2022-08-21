#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main() {
    int n = 0;
    int x;
    vi numbers = vi();
    while(scanf("%d", &x) != EOF) {
        if (n == 0) {
            numbers.push_back(x);
        } else {
            vi::iterator it = lower_bound(numbers.begin(), numbers.end(), x);
            numbers.insert(it, x);
        }
        n++;
        long long int ans = n % 2 ?
            numbers[n / 2] :
            ((long long int) numbers[n / 2 - 1] + (long long int) numbers[n / 2]) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}