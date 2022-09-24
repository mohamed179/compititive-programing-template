#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef vector<string> vs;
typedef map<string, int> msi;

vs tokenize(string const str, string const delemiter) {
    int start, end = - (int) delemiter.size();
    vs tokens = vs();
    do {
        start = end + delemiter.size();
        end = str.find(delemiter, start);
        tokens.push_back(str.substr(start, end - start));
    } while (end != -1);
    return tokens;
}

int main() {
    int m, n;
    cin >> m >> n;
    msi dictionary = msi();
    for (int i = 0; i < m; i++) {
        string word;
        int dollar;
        cin >> word >> dollar;
        dictionary[word] = dollar;
    }
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        string description = "";
        while(true) {
            getline(cin, line);
            if (line != ".") {
                description += " " + line;
            } else {
                break;
            }
        }
        vs tokens = tokenize(description, " ");
        int ans = 0;
        for (int j = 0; j < (int) tokens.size(); j++) {
            string token = tokens[j];
            msi::iterator it = dictionary.find(token);
            if (it != dictionary.end()) {
                ans += it->second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}