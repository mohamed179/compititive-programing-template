#include <cstdio>
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
    // your code here...
    return 0;
}