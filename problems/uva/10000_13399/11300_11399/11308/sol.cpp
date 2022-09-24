#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef map<string, int> msi;
typedef pair<int, string> is;
typedef vector<is> vis;

int main() {
    int t;
    cin >> t;
    string line;
    while(t--) {
        string binder;
        getline(cin, line);
        getline(cin, binder);
        transform(binder.begin(), binder.end(), binder.begin(), ::toupper);
        int m, n, b;
        cin >> m >> n >> b;
        msi prices = msi();
        for (int i = 0; i < m; i++) {
            string ingredient;
            int price;
            cin >> ingredient >> price;
            prices[ingredient] = price;
        }
        vis recipes = vis();
        for (int i = 0; i < n; i++) {
            string recipe;
            getline(cin, line);
            getline(cin, recipe);
            int k;
            cin >> k;
            int price = 0;
            while(k--) {
                string ingredient;
                int units;
                cin >> ingredient >> units;
                price += prices[ingredient] * units;
            }
            recipes.push_back(is(price, recipe));
        }
        sort(recipes.begin(), recipes.end());
        cout << binder << endl;
        for (int i = 0; i < n; i++) {
            is recipe = recipes[i];
            if (recipe.first <= b) {
                cout << recipe.second << endl;
            } else {
                if (i == 0) {
                    cout << "Too expensive!" << endl;
                }
                break;
            }
        }
        cout << endl;
    }
    return 0;
}