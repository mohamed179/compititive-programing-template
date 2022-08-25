#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000000

int main() {
    char code[MAX];
    while(scanf("%s", code) && strcmp(code, "#")) {
        int fIdx = -1, sIdx = -1;
        int n = strlen(code);
        for (int i = 0; i < n - 1; i++) {
            if (code[i] < code[i + 1]) fIdx = i;
        }
        if (fIdx == -1) {
            printf("No Successor\n");
        } else {
            sort(code + fIdx + 1, code + n);
            for (sIdx = fIdx + 1; code[sIdx] <= code[fIdx]; sIdx++);
            char swap = code[fIdx];
            code[fIdx] = code[sIdx];
            code[sIdx] = swap;
            printf("%s\n", code);
        }
    }
    return 0;
}