#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;

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
    // your code here...
    return 0;
}