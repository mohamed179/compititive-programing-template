#include <iostream>
#include <set>
#include <map>
using namespace std;

#define END "END"

typedef pair<string, string> ss;
typedef set<ss> sss;
typedef map<string, string> mss;

int main() {
    string bookString;
    mss titles;
    sss stock;
    sss returned;
    while(getline(cin, bookString) && bookString != END) {
        int idx = bookString.find("\" by ");
        stock.insert(ss(bookString.substr(idx + 5), bookString.substr(0, idx + 1)));
        titles[bookString.substr(0, idx + 1)] = bookString.substr(idx + 5);
    }
    while(getline(cin, bookString) && bookString != END) {
        int idx = bookString.find(" ");
        string query = bookString.substr(0, idx);
        if (query == "BORROW") {
            // borrow
            string title = bookString.substr(idx + 1);
            string author = titles[title];
            ss book = ss(author, title);
            stock.erase(book);
        } else if (query == "RETURN") {
            // return
            string title = bookString.substr(idx + 1);
            string author = titles[title];
            ss book = ss(author, title);
            returned.insert(book);
        } else {
            // shelve
            while(!returned.empty()) {
                ss bookToBeShelved = *returned.begin();
                sss::iterator it = stock.lower_bound(bookToBeShelved);
                bool first = false;
                ss bookBefore;
                if (it == stock.begin()) {
                    first = true;
                } else if (it == stock.end()) {
                    bookBefore = *stock.rbegin();
                } else {
                    it--;
                    bookBefore = *it;
                }
                if (first) cout << "Put " << bookToBeShelved.second << " first" << endl;
                else       cout << "Put " << bookToBeShelved.second << " after " << bookBefore.second << endl;
                returned.erase(bookToBeShelved);
                stock.insert(bookToBeShelved);
            }
            cout << "END" << endl;
        }
    }
    return 0;
}