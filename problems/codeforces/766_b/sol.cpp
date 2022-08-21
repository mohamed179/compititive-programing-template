#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, lengths[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lengths[i]);
    }
    sort(lengths, lengths + n);
    bool yes = false;
    for (int i = 0; i < n - 2 && !yes; i++) {
        if (lengths[i] + lengths[i + 1] > lengths[i + 2]) yes = true;
    }
    printf(yes ? "YES\n" : "NO\n");
    return 0;
}