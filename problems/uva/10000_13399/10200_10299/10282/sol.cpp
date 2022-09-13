#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> dictionary = map<string, string>();
    string line;
    while(true) {
        getline(cin, line);
        if (line == "") break;
        int spaceIdx = line.find(' ');
        string englishWord = line.substr(0, spaceIdx);
        string foreignWord = line.substr(spaceIdx + 1);
        dictionary[foreignWord] = englishWord;
    }
    while(!cin.eof()) {
        getline(cin, line);
        if (line == "") break;
        if (dictionary.find(line) != dictionary.end()) {
            cout << dictionary[line] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    return 0;
}