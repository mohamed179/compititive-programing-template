#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// to be sorted: pts wins gd gs _gp tn

// to be visualized: rank tn pts gp wins tie lose gd gs ga

typedef map<string, int> msi;

class Rank {
public:
    int idx;
    int pts, wins, gd, gs, gp;
    string tn;
    int ties, loses, ga;
    Rank(string tn, int idx,
         int pts = 0,
         int gp = 0, int wins = 0,
         int ties = 0, int loses = 0,
         int gd = 0, int gs = 0, int ga = 0) {
        this->tn = tn; this->idx = idx;
        this->pts = pts,
        this->gp = gp; this->wins = wins;
        this->ties = ties; this->loses = loses;
        this->gd = gd; this->gs = gs; this->ga = ga;
    }
    bool operator< (Rank rank2) {
        return checkPts(rank2);
    }
    bool checkPts(Rank rank2) {
        if (this->pts > rank2.pts) {
            return true;
        } else if (this->pts == rank2.pts) {
            return checkWins(rank2);
        } else {
            return false;
        }
    }
    bool checkWins(Rank rank2) {
        if (this->wins > rank2.wins) {
            return true;
        } else if (this->wins == rank2.wins) {
            return checkGoalDiff(rank2);
        } else {
            return false;
        }
    }
    bool checkGoalDiff(Rank rank2) {
        if (this->gd > rank2.gd) {
            return true;
        } else if (this->gd == rank2.gd) {
            return checkGoalScored(rank2);
        } else {
            return false;
        }
    }
    bool checkGoalScored(Rank rank2) {
        if (this->gs > rank2.gs) {
            return true;
        } else if (this->gs == rank2.gs) {
            return checkGamesPlayed(rank2);
        } else {
            return false;
        }
    }
    bool checkGamesPlayed(Rank rank2) {
        if (this->gp < rank2.gp) {
            return true;
        } else if (this->gs == rank2.gs) {
            return checkTeamName(rank2);
        } else {
            return false;
        }
    }
    bool checkTeamName(Rank rank2) {
        return this->tn < rank2.tn;
    }
};

int main() {
    int N;
    cin >> N;
    string line;
    getline(cin, line);
    for (int TC = 0; TC < N; TC++) {
        string tourment;
        getline(cin, tourment);
        int T;
        cin >> T;
        getline(cin, line);
        msi teams = msi();
        vector<string> teamNames = vector<string>();
        vector<Rank> ranks = vector<Rank>();
        for (int i = 0; i < T; i++) {
            string team;
            getline(cin, team);
            teams[team] = i;
            teamNames.push_back(team);
            transform(team.begin(), team.end(), team.begin(), ::tolower);
            ranks.push_back(Rank(team, i));
        }
        int G;
        cin >> G;
        getline(cin, line);
        for (int i = 0; i < G; i++) {
            string game;
            getline(cin, game);
            int fHash = game.find('#');
            int sHash = game.find('#', fHash + 1);
            int at    = game.find('@');
            string fTeam = game.substr(0, fHash);
            string sTeam = game.substr(sHash + 1);
            int fScore = stoi(game.substr(fHash + 1, at - fHash));
            int sScore = stoi(game.substr(at + 1, sHash - at - 1));
            int fIdx = teams[fTeam];
            int sIdx = teams[sTeam];
            // set first team
            ranks[fIdx].gp++;
            ranks[fIdx].gs += fScore;
            ranks[fIdx].ga += sScore;
            ranks[fIdx].gd = ranks[fIdx].gs - ranks[fIdx].ga;
            // set second team
            ranks[sIdx].gp++;
            ranks[sIdx].gs += sScore;
            ranks[sIdx].ga += fScore;
            ranks[sIdx].gd = ranks[sIdx].gs - ranks[sIdx].ga;
            // set winer and loser
            if (fScore > sScore) {
                ranks[fIdx].wins++;
                ranks[fIdx].pts += 3;
                ranks[sIdx].loses++;
            } else if (sScore > fScore) {
                ranks[sIdx].wins++;
                ranks[sIdx].pts += 3;
                ranks[fIdx].loses++;
            } else {
                ranks[fIdx].ties++;
                ranks[fIdx].pts += 1;
                ranks[sIdx].ties++;
                ranks[sIdx].pts += 1;
            }
        }
        sort(ranks.begin(), ranks.end());
        if (TC) cout << endl;
        cout << tourment << endl;
        for (int i = 0; i < T; i++) {
            cout << (i + 1) << ") "
                 << teamNames[ranks[i].idx] << " "
                 << ranks[i].pts << "p, "
                 << ranks[i].gp << "g "
                 << "(" << ranks[i].wins
                 << "-" << ranks[i].ties
                 << "-" << ranks[i].loses << "), "
                 << ranks[i].gd << "gd "
                 << "(" << ranks[i].gs
                 << "-" << ranks[i].ga << ")"
                 << endl;
        }
    }
    return 0;
}