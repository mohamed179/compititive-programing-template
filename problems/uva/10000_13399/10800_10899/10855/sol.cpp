#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N, n;
vector<string> f, s;

int checkUp() {
    int ans = 0;
    for (int i = 0; i < N - n + 1; i++) {
        for (int j = 0; j < N - n + 1; j++) {
            bool found = true;
            for (int k = 0; found && k < n; k++) {
                for (int l = 0; found && l < n; l++) {
                    if (f[i + k][j + l] != s[k][l]) found = false;
                }
            }
            ans += (int) found;
        }
    }
    return ans;
}

int checkRight() {
    int ans = 0;
    for (int i = 0; i < N - n + 1; i++) {
        for (int j = 0; j < N - n + 1; j++) {
            bool found = true;
            for (int k = 0; found && k < n; k++) {
                for (int l = 0; found && l < n; l++) {
                    if (f[i + k][j + l] != s[n - 1 - l][k]) found = false;
                }
            }
            ans += (int) found;
        }
    }
    return ans;
}

int checkDown() {
    int ans = 0;
    for (int i = 0; i < N - n + 1; i++) {
        for (int j = 0; j < N - n + 1; j++) {
            bool found = true;
            for (int k = 0; found && k < n; k++) {
                for (int l = 0; found && l < n; l++) {
                    if (f[i + k][j + l] != s[n - 1 - k][n - 1 - l]) found = false;
                }
            }
            ans += (int) found;
        }
    }
    return ans;
}

int checkLeft() {
    int ans = 0;
    for (int i = 0; i < N - n + 1; i++) {
        for (int j = 0; j < N - n + 1; j++) {
            bool found = true;
            for (int k = 0; found && k < n; k++) {
                for (int l = 0; found && l < n; l++) {
                    if (f[i + k][j + l] != s[l][n - 1 - k]) found = false;
                }
            }
            ans += (int) found;
        }
    }
    return ans;
}

int main() {
    while(cin >> N >> n && N && n) {
        f.clear(); s.clear();
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            f.push_back(str);
        }
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            s.push_back(str);
        }
        int up = checkUp();
        int right = checkRight();
        int down = checkDown();
        int left = checkLeft();
        cout << up << " " << right << " " << down << " " << left << endl;
    }
    return 0;
}