#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

// data needed:     pts gd gs ga team teamIdx
// data represeted: (pos) team pts mp gs ga gd (per)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> iiii;
typedef pair<string, int> si;
typedef pair<iiii, si> iiii_si;
typedef vector<iiii_si> viiii_si;
typedef map<string, int> msi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<ii, ii> ii_ii;
typedef vector<ii_ii> vii_ii;
typedef vector<vii_ii> vvii_ii;

int stringComp(string str1, string str2);
void calculate(vs teams, vii_ii matchs);

int main() {
    int t, g;
    vvs inputTeams = vvs();
    vvii_ii inputMatchs = vvii_ii();
    while(scanf("%d %d", &t, &g)) {
        if (!t && !g) break;
        msi teamsMap;
        vs teams;
        vii_ii matchs;
        for (int i = 0; i < t; i++) {
            string team;
            cin >> team;
            teamsMap[team] = i;
            teams.push_back(team);
        }
        inputTeams.push_back(teams);
        for (int i = 0; i < g; i++) {
            string teamH, teamA, temp;
            ii_ii match;
            cin >> teamH >> match.first.second;
            cin >> temp;
            cin >> match.second.second >> teamA;
            if (teamsMap.find(teamH) != teamsMap.end()) {
                match.first.first = teamsMap[teamH];
            }
            else {
                match.first.first = -1;
            }
            match.second.first = teamsMap[teamA];
            matchs.push_back(match);
        }
        inputMatchs.push_back(matchs);
    }
    for (int i = 0; i < (int) inputTeams.size(); i++) {
        if (i) cout << endl;
        calculate(inputTeams[i], inputMatchs[i]);
    }
    return 0;
}

void calculate(vs teams, vii_ii matchs) {
    int t = (int) teams.size();
    int g = (int) matchs.size();
    viiii_si table = viiii_si(t, iiii_si());
    vi matchPlayed = vi(t, 0);
    for (int i = 0; i < t; i++) {
        table[i].second.first = teams[i];
        table[i].second.second = i;
        transform(table[i].second.first.begin(), table[i].second.first.end(), table[i].second.first.begin(), ::tolower);
    }
    for (int i = 0; i < g; i++) {
        ii_ii match = matchs[i];
        ii home = match.first;
        ii away = match.second;
        if (home.first != -1) matchPlayed[home.first]++;
        if (away.first != -1) matchPlayed[away.first]++;
        if (home.second > away.second) {
            if (home.first != -1) table[home.first].first.first -= 3;
        } else if (away.second > home.second) {
            if (away.first != -1) table[away.first].first.first -= 3;
        } else {
            if (home.first != -1) table[home.first].first.first -= 1;
            if (away.first != -1) table[away.first].first.first -= 1;
        }
        if (home.first != -1) {
            table[home.first].first.second.second.first -= home.second;
            table[home.first].first.second.second.second -= away.second;
            table[home.first].first.second.first =
                - ((- table[home.first].first.second.second.first) -
                (- table[home.first].first.second.second.second));
        }
        if (away.first != -1) {
            table[away.first].first.second.second.first -= away.second;
            table[away.first].first.second.second.second -= home.second;
            table[away.first].first.second.first =
                - ((- table[away.first].first.second.second.first) -
                (- table[away.first].first.second.second.second));
        }
    }
    sort(table.begin(), table.end());
    for (int i = 0; i < t; i++) {
        iiii_si team = table[i];
        if (!i || team.first != table[i - 1].first) {
            cout << setw(2)  << i + 1 << "."
                 << setw(16) << teams[team.second.second]
                 << setw(4)  << - team.first.first
                 << setw(4)  << matchPlayed[team.second.second]
                 << setw(4)  << - team.first.second.second.first
                 << setw(4)  << - team.first.second.second.second
                 << setw(4)  << - team.first.second.first;
            if (matchPlayed[team.second.second]) printf("%7.2f\n", (double) (- team.first.first) * 100.0 / ((double) matchPlayed[team.second.second] * 3.0));
            else printf("%7s\n", "N/A");
            
        } else {
            cout << setw(3)  << ""
                 << setw(16) << teams[team.second.second]
                 << setw(4)  << - team.first.first
                 << setw(4)  << matchPlayed[team.second.second]
                 << setw(4)  << - team.first.second.second.first
                 << setw(4)  << - team.first.second.second.second
                 << setw(4)  << - team.first.second.first;
            if (matchPlayed[team.second.second]) printf("%7.2f\n", (double) (- team.first.first) * 100.0 / ((double) matchPlayed[team.second.second] * 3.0));
            else printf("%7s\n", "N/A");
        }
    }
}