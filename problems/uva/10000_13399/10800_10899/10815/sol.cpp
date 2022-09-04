#include <iostream>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

typedef set<string> ss;

int main() {
    ss dectionary;
    while(!cin.eof()) {
        string line;
        getline(cin, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        for (int i = 0; i < (int) line.size(); i++) {
            if (line[i] < 'a' || line[i] > 'z') line[i] = ' ';
        }
        stringstream sstream = stringstream(line);
        while(sstream) {
            string word;
            sstream >> word;
            if (!word.empty()) dectionary.insert(word);
        }
    }
    for (ss::iterator it = dectionary.begin(); it != dectionary.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}