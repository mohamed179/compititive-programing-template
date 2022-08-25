#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

#define UNSOLVED 0
#define SOLVED 1
#define NO_SUBMIT 0
#define SUBMIT 1

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main() {
    int T;
    scanf("%d", &T);
    int solved[110][15];
    int hasSubmit[110];
    int penality[110][15];
    iii contestants[110];
    string entry;
    getline(cin, entry);
    getline(cin, entry);
    for (int t = 1; t <= T; t++) {
        if (t > 1) printf("\n");
        // reset every thing before every test case
        memset(solved, UNSOLVED, sizeof solved);
        memset(hasSubmit, NO_SUBMIT, sizeof hasSubmit);
        memset(penality, 0, sizeof penality);
        for (int i = 0; i < 110; i++) {
            contestants[i] = iii(ii(0, 0), i);
        }
        // read line by line
        while(getline(cin, entry) && entry != "") {
            stringstream ss(entry);
            int c, p, time;
            char l;
            ss >> c >> p >> time >> l;
            hasSubmit[c] = SUBMIT;
            if (l == 'C' && solved[c][p] == UNSOLVED) {
                solved[c][p] = SOLVED;
                contestants[c].first.first--;
                contestants[c].first.second += time;
            } else if (l == 'I' && solved[c][p] == UNSOLVED) {
                contestants[c].first.second += 20;
                penality[c][p] += 20;
            }
        }
        // remove calculated penality for unsolved problems
        for (int c = 1; c <= 100; c++) {
            for (int p = 1; p <= 9; p++) {
                if (solved[c][p] == UNSOLVED) {
                    contestants[c].first.second -= penality[c][p];
                }
            }
        }
        // sort ascending according to solved => penality => contestant number
        sort(contestants, contestants + 101);
        for (int i = 0; i < 110; i++) {
            iii c = contestants[i];
            if (hasSubmit[c.second]) {
                printf("%d %d %d\n", c.second, -c.first.first, c.first.second);
            }
        }
    }
    return 0;
}