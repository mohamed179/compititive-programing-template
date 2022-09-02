#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UFDS {
private:
    int numSets;
    vi p, rank, size;

public:
    UFDS(int N) {
        numSets = N;
        rank.assign(N, 0);
        size.assign(N, 1);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) {
        if (p[i] == i) return i;
        else return p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSets(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = findSet(i);
            int y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
            } else {
                p[x] = y;
                size[y] += size[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        return size[findSet(i)];
    }
};

int main() {
    int t;
    cin >> t;
    for (int TC = 0; TC < t; TC++) {
        int n;
        cin >> n;
        UFDS ufds(n);
        int success = 0, fail = 0;
        string query;
        getline(cin, query);
        while(getline(cin, query) && query != "") {
            stringstream ss = stringstream(query);
            char q;
            int i, j;
            ss >> q >> i >> j;
            i--; j--;
            switch(q) {
                case 'c':
                    ufds.unionSets(i, j);
                    break;
                case 'q':
                    ufds.isSameSet(i, j) ? success++ : fail++;
                    break;
                default:
                    break;
            }
        }
        if (TC) cout << endl;
        cout << success << "," << fail << endl;
    }
    return 0;
}