#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MIN(a, b) ((a) > (b)) ? (b) : (a)

typedef vector<int> vi;
typedef priority_queue<int> pqi;

int main() {
    int N;
    scanf("%d", &N);
    for (int TC = 0; TC < N; TC++) {
        int B, SG, SB;
        scanf("%d %d %d", &B, &SG, &SB);
        pqi gRace = pqi();
        pqi bRace = pqi();
        for (int i = 0; i < SG; i++) {
            int lemming;
            scanf("%d", &lemming);
            gRace.push(lemming);
        }
        for (int i = 0; i < SB; i++) {
            int lemming;
            scanf("%d", &lemming);
            bRace.push(lemming);
        }
        while(!gRace.empty() && !bRace.empty()) {
            int min = MIN(MIN((int) gRace.size(), (int) bRace.size()), B);
            vi gBattleLemmings = vi();
            vi bBattleLemmings = vi();
            for (int i = 0; i < min; i++) {
                // getting ready for the battlegrounds
                int lemming = gRace.top();
                gRace.pop();
                gBattleLemmings.push_back(lemming);
                lemming = bRace.top();
                bRace.pop();
                bBattleLemmings.push_back(lemming);
            }
            for (int i = 0; i < min; i++) {
                // battle
                int gLemming = gBattleLemmings[i];
                int bLemming = bBattleLemmings[i];
                if (gLemming > bLemming) {
                    gRace.push(gLemming - bLemming);
                } else if (bLemming > gLemming) {
                    bRace.push(bLemming - gLemming);
                }
            }
        }
        if (TC) printf("\n");
        if (gRace.empty() && bRace.empty()) {
            printf("green and blue died\n");
        } else if (gRace.empty()) {
            printf("blue wins\n");
            while(!bRace.empty()) {
                printf("%d\n", bRace.top());
                bRace.pop();
            }
        } else {
            printf("green wins\n");
            while(!gRace.empty()) {
                printf("%d\n", gRace.top());
                gRace.pop();
            }
        }
    }
    return 0;
}