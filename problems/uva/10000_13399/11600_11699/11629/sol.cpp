#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef vector<string> vs;
typedef pair<vs, double> vsd;
typedef map<string, double> msd;

vs tokenize(string const str, string const delemiter);
bool decide(msd const parties, vsd const guess, string const compare);

int main() {
    int p, g;
    cin >> p >> g;
    msd parties = msd();
    for (int i = 0; i < p; i++) {
        string party;
        double percentage;
        cin >> party >> percentage;
        parties[party] = percentage;
    }
    string line;
    getline(cin, line);
    for (int guessIdx = 1; guessIdx <= g; guessIdx++) {
        getline(cin, line);
        vs tokens = tokenize(line, " ");
        vsd guess = vsd(vs(), 0.0);
        for (int i = 0; i < (int) tokens.size() - 1; i++) {
            string token = tokens[i];
            if (token == "<" || token == ">" || token == "<=" || token == ">=" || token == "=") {
                guess.second = stoi(tokens[i + 1]);
            } else if (token == "+") {
                continue;
            } else {
                guess.first.push_back(token);
            }
        }
        bool ans = decide(parties, guess, tokens[(int) tokens.size() - 2]);
        cout << "Guess #" << guessIdx << " was "
             << (ans ? "correct." : "incorrect.")
             << endl;
    }
    return 0;
}

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

bool decide(msd const parties, vsd const guess, string const compare) {
    double rightPercentage = 0.0;
    for (int i = 0; i < (int) guess.first.size(); i++) {
        rightPercentage += parties.at(guess.first[i]);
    }
    if (compare == ">") {
        return rightPercentage - guess.second > 0.099f;
    } else if (compare == "<") {
        return guess.second - rightPercentage > 0.099f;
    } else if (compare == ">=") {
        return rightPercentage - guess.second > 0.099f ||
               fabs(rightPercentage - guess.second) < 0.00001f;
    } else if (compare == "<=") {
        return guess.second - rightPercentage > 0.099f ||
               fabs(guess.second - rightPercentage) < 0.00001f;
    } else {
        return fabs(guess.second - rightPercentage) < 0.00001f;
    }
}