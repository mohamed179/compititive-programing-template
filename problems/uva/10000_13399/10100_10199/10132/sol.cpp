#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<string> vs;

bool compareFn(string const fragment1, string const fragment2);
vs findProposals(vs const fragments, int const len);
string findFile(vs const propsals, int const files);

int main() {
    int t;
    cin >> t;
    string line;
    getline(cin, line);
    getline(cin, line);
    vs fragments;
    for (int TC = 0; TC < t; TC++) {
        fragments = vs();
        while(true) {
            getline(cin, line);
            if (line == "") break;
            fragments.push_back(line);
        }
        sort(fragments.begin(), fragments.end(), compareFn);
        int files = ((int) fragments.size()) / 2;
        int len = (int) fragments[0].size() + (int) fragments[(int) fragments.size() - 1].size();
        vs proposals = findProposals(fragments, len);
        sort(proposals.begin(), proposals.end());
        string ans = findFile(proposals, files);
        if (TC) cout << endl;
        cout << ans << endl;
    }
    return 0;
}

bool compareFn(string const fragment1, string const fragment2) {
    if ((int) fragment1.size() < (int) fragment2.size()) {
        return true;
    } else if ((int) fragment1.size() > (int) fragment2.size()) {
        return false;
    } else {
        return fragment1 < fragment2;
    }
}

vs findProposals(vs const fragments, int const len) {
    vs proposals = vs();
    string currentSmallFragment = "";
    for (int i = 0; i < ((int) fragments.size()) / 2; i++) {
        if (fragments[i] != currentSmallFragment) {
            currentSmallFragment = fragments[i];
            string currentBigFragment = "";
            for (int j = (int) fragments.size() - 1; j >= ((int) fragments.size()) / 2; j--) {
                if ((int) fragments[j].size() + (int) currentSmallFragment.size() != len) continue;
                if (fragments[j] != currentBigFragment) {
                    currentBigFragment = fragments[j];
                    proposals.push_back(currentSmallFragment + currentBigFragment);
                    proposals.push_back(currentBigFragment + currentSmallFragment);
                }
            }
        }
    }
    return proposals;
}

string findFile(vs const propsals, int const files) {
    int count = 1;
    string ans = propsals[0];
    for (int i = 1; i < (int) propsals.size(); i++) {
        propsals[i] == propsals[i - 1] ? count++ : count = 1;
        if (count == files) {
            ans = propsals[i];
            break;
        }
    }
    return ans;
}