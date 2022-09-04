#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

typedef set<string> ss;
typedef vector<string> vs;

int main() {
    string book = "";
    ss dectionary;
    while(!cin.eof()) {
        string line;
        getline(cin, line);
        if (line == "$") break;
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        book = book + "A" + line;
    }
    for (int i = 0; i < (int) book.size(); i++) {
        if ((book[i] < 'a' || book[i] > 'z') && book[i] != '-' && book[i] != 'A') book[i] = ' ';
    }
    while(true) {
        int idx;
        idx = (int) book.find("-A");
        if (idx == -1 || idx == (int) book.size()) break;
        book.erase(idx, 2);
    }
    for (int i = 0; i < (int) book.size(); i++) {
        if (book[i] == 'A') book[i] = ' ';
    }
    stringstream sstream = stringstream(book);
    while(sstream) {
        string word;
        sstream >> word;
        if (!word.empty()) dectionary.insert(word);
    }
    for (ss::iterator it = dectionary.begin(); it != dectionary.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}