#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef stack<string> ss;
typedef vector<ss> vss;

void turn(vss *piles);

int main() {
    int n = 52;
    string card;
    while(cin >> card && card != "#") {
        vss piles = vss(1, ss());
        piles[0].push(card);
        for (int i = 1; i < 52; i++) {
            cin >> card;
            piles.push_back(ss());
            piles[(int) piles.size() - 1].push(card);
            turn(&piles);
        }
        int finalSize = (int) piles.size();
        if (finalSize == 1) cout << "1 pile remaining:";
        else cout << finalSize << " piles remaining:";
        for (int i = 0; i < finalSize; i++) {
            cout << " " << (int) piles[i].size();
        }
        cout << endl;
    }
    return 0;
}

void turn(vss *piles) {
    for (int i = 1; i < (int) piles->size(); i++) {
        bool startOver = false;
        string top = piles->at(i).top();
        if (i >= 3) {
            string thirdBefore = piles->at(i - 3).top();
            if (top[0] == thirdBefore[0] || top[1] == thirdBefore[1]) {
                piles->at(i).pop();
                piles->at(i - 3).push(top);
                startOver = true;
            }
        }
        if (!startOver) {
            string firstBefore = piles->at(i - 1).top();
            if (top[0] == firstBefore[0] || top[1] == firstBefore[1]) {
                piles->at(i).pop();
                piles->at(i - 1).push(top);
                startOver = true;
            }
        }
        if (!piles->at(i).size()) {
            piles->erase(next(piles->begin(), i));
        }
        if (startOver) i = 0;
    }
}