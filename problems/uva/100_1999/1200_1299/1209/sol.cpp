#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NOT_FOUND "#"
#define INF 1000000000

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, string> is;
typedef vector<is> vis;

string findBefore(string permutation);
string findAfter(string permutation);
is minimumAbsoluteDistance(string permutation);

int main() {
    string username;
    while(true) {
        getline(cin, username);
        if (username == "") break;
        vis permutations = vis();
        permutations.push_back(minimumAbsoluteDistance(username));
        string before = username;
        for (int i = 10; i >= 1; i--) {
            before = findBefore(before);
            if (before == NOT_FOUND) break;
            permutations.push_back(minimumAbsoluteDistance(before));
        }
        string after = username;
        for (int i = 12; i <= 21; i++) {
            after = findAfter(after);
            if (after == NOT_FOUND) break;
            permutations.push_back(minimumAbsoluteDistance(after));
        }
        sort(permutations.begin(), permutations.end());
        is ans = permutations[0];
        cout << ans.second << (-ans.first) << endl;
    }
    return 0;
}

string findBefore(string permutation) {
    int len = (int) permutation.size();
    int idx = len - 1;
    for ( ; idx >= 1; idx--) {
        if (permutation[idx] < permutation[idx - 1]) break;
    }
    if (idx == 0) return NOT_FOUND;
    int min = -INF;
    int max = permutation[idx - 1];
    int idx2 = idx;
    for (int i = idx; i < len; i++) {
        if (permutation[i] > min && permutation[i] < max) {
            idx2 = i;
            min = permutation[i];
        }
    }
    char temp = permutation[idx - 1];
    permutation[idx - 1] = permutation[idx2];
    permutation[idx2] = temp;
    sort(permutation.begin() + idx, permutation.end(), greater<int>());
    return permutation;
}

string findAfter(string permutation) {
    int len = (int) permutation.size();
    int idx = len - 1;
    for ( ; idx >= 1; idx--) {
        if (permutation[idx] > permutation[idx - 1]) break;
    }
    if (idx == 0) return NOT_FOUND;
    int min = permutation[idx - 1];
    int max = INF;
    int idx2 = idx;
    for (int i = idx; i < len; i++) {
        if (permutation[i] > min && permutation[i] < max) {
            idx2 = i;
            max = permutation[i];
        }
    }
    char temp = permutation[idx - 1];
    permutation[idx - 1] = permutation[idx2];
    permutation[idx2] = temp;
    sort(permutation.begin() + idx, permutation.end());
    return permutation;
}

is minimumAbsoluteDistance(string permutation) {
    int len = (int) permutation.size();
    vi distances = vi();
    for (int i = 0; i < len - 1; i++) {
        distances.push_back(MAX(permutation[i] - permutation[i + 1], permutation[i + 1] - permutation[i]));
    }
    int min = INF;
    for (int i = 0; i < len - 1; i++) {
        if (distances[i] < min) min = distances[i];
    }
    return is(-min, permutation);
}