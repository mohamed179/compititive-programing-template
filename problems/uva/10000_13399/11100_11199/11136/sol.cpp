#include <cstdio>
#include <set>
using namespace std;

int main () {
    int n;
    while(scanf("%d", &n) && n) {
        long long int ans = 0;
        multiset<int, greater<int>> urn = multiset<int, greater<int>>();
        while(n--) {
            int k;
            scanf("%d", &k);
            for (int i = 0; i < k; i++) {
                int bill;
                scanf("%d", &bill);
                urn.insert(bill);
            }
            int maxBill = *urn.begin();
            int minBill = *urn.rbegin();
            ans += maxBill - minBill;
            urn.erase(urn.find(maxBill));
            urn.erase(urn.find(minBill));
        }
        printf("%lld\n", ans);
    }
    return 0;
}