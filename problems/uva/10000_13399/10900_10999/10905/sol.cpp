#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<string> vs;

bool compareFn(string const num1, string const num2);

int main() {
    int n;
    while(true) {
        cin >> n;
        if (!n) break;
        int maxLen = 0;
        vs nums = vs();
        for (int i = 0; i < n; i++) {
            string num;
            cin >> num;
            nums.push_back(num);
            maxLen = (int) num.size() > maxLen ? (int) num.size() : maxLen;
        }
        sort(nums.begin(), nums.end(), compareFn);
        for (int i = n - 1; i >= 0; i--) {
            cout << nums[i];
        }
        cout << endl;
    }
    return 0;
}

bool compareFn(string const num1, string const num2) {
    int len1 = (int) num1.size();
    int len2 = (int) num2.size();
    for (int i = 0; i < len1 && i < len2; i++) {
        if (num1[i] < num2[i]) return true;
        else if (num1[i] > num2[i]) return false;
    }
    if (len1 < len2) {
        return compareFn(num1, num2.substr(len1));
    } else if (len1 > len2) {
        return compareFn(num1.substr(len2), num2);
    } else {
        return true;
    }
}