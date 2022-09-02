#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef set<string> ss;
typedef map<string, vi> msvi;

int main() {
    vs titles = vs();
    ss ignored = ss();
    msvi keyword = msvi();
    string word;
    while(cin >> word && word != "::") {
        ignored.insert(word);
    }
    string title;
    getline(cin, title);
    while(cin.good() && !cin.eof()) {
        getline(cin, title);
        if (title == "") break;
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        titles.push_back(title);
        stringstream iss = stringstream(title);
        while(true) {
            iss >> word;
            if (!iss) break;
            if (ignored.find(word) == ignored.end()) {
                if (keyword.find(word) == keyword.end()) {
                    vi hasThisKeyword = vi();
                    hasThisKeyword.push_back((int) titles.size() - 1);
                    keyword[word] = hasThisKeyword;
                } else {
                    keyword[word].push_back((int) titles.size() - 1);
                }
            }
        }
    }
    for (msvi::iterator it = keyword.begin(); it != keyword.end(); it++) {
        word = it->first;
        string uWord = word;
        transform(uWord.begin(), uWord.end(), uWord.begin(), ::toupper);
        vi hasThisKeyword = it->second;
        for (int i = 0; i < (int) hasThisKeyword.size(); i++) {
            if (!i || hasThisKeyword[i] != hasThisKeyword[i - 1]) {
                title = titles[hasThisKeyword[i]];
                regex r = regex("\\b" + word + "\\b");
                for(sregex_iterator it = std::sregex_iterator(title.begin(), title.end(), r);
                    it != std::sregex_iterator(); ++it ) {
                    smatch m = *it;
                    int idx = m.position();
                    cout << title.substr(0, idx)
                         << uWord
                         << title.substr(idx + (int) word.size())
                         << endl;
                }
            }
        }
    }
    return 0;
}