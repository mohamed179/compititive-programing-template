#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, maxLen;
    vector<string> files;
    cout.setf(ios::left, ios::adjustfield);
    while(!cin.eof()) {
        if (!(cin >> n)) break;
        files = vector<string>();
        maxLen = 0;
        for (int i = 0; i < n; i++) {
            string file;
            cin >> file;
            files.push_back(file);
            int len = (int) file.size();
            maxLen = len > maxLen ? len : maxLen;
        }
        sort(files.begin(), files.end());
        maxLen += 2;
        int columns = 62 / maxLen;
        int rows = n / columns;
        if (n % columns) rows++;
        cout << string(60, '-') << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (i + j * rows >= n) break;
                if (j < columns - 1 && i + (j + 1) * rows < n) cout << setw(maxLen) << files[i + j * rows];
                else cout << setw(maxLen - 2) << files[i + j * rows];
            }
            cout << endl;
        }
    }
    return 0;
}