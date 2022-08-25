#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

typedef list<char> lc;

int main() {
    char input[100010];
    while(scanf("%s", input) != EOF) {
        int n = strlen(input);
        lc text = lc();
        lc::iterator nextIt = text.end();
        for (int i = 0; i < n; i++) {
            char ch = input[i];
            switch (ch) {
                case '[':
                    nextIt = text.begin();
                    break;
                case ']':
                    nextIt = text.end();
                    break;
                default:
                    if (nextIt == text.end()) {
                        text.push_back(input[i]);
                    } else {
                        text.insert(nextIt, 1, ch);
                    }
                    break;
            }
        }
        for (lc::iterator it = text.begin(); it != text.end(); it++) {
            printf("%c", *it);
        }
        printf("\n");
    }
    return 0;
}