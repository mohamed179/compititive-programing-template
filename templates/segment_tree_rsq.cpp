#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
    vi st, A;
    int n;
    int left(int p);
    int right(int p);
    void build(int p, int L, int R);
    int rsq(int p, int L, int R, int i, int j);
    void update(int p, int L, int R, int i, int value);
    void rupdate(int p, int L, int R, int i, int j, int value);

public:
    SegmentTree(vi &_A);
    int rsq(int i, int j);
    void update(int i, int value);
    void insert(int i, int value);
    void erase(int i);
    void rupdate(int i, int j, int value);
};

int main() {
    // your code here...
    return 0;
}

SegmentTree::SegmentTree(vi &_A) {
    A = _A;
    n = (int) A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
}

int SegmentTree::rsq(int i, int j) {
    return rsq(1, 0, n -1, i, j);
}

void SegmentTree::update(int i, int value) {
    update(1, 0, n - 1, i, value);
}

void SegmentTree::insert(int i, int value) {
    A.insert(A.begin() + i, value);
    n++;
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
}

void SegmentTree::erase(int i) {
    A.erase(A.begin() + i);
    n--;
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
}

void SegmentTree::rupdate(int i, int j, int value) {
    rupdate(1, 0, n - 1, i, j, value);
}

int SegmentTree::left(int p) {
    return p << 1;
}

int SegmentTree::right(int p) {
    return (p << 1) + 1;
}

void SegmentTree::build(int p, int L, int R) {
    if (L == R) {
        st[p] = A[L];
    } else {
        build(left(p), L, (L + R) / 2);
        build(right(p), (L + R) / 2 + 1, R);
        st[p] = st[left(p)] + st[right(p)];
    }
}

int SegmentTree::rsq(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return 0;
    if (L >= i && R <= j) return st[p];

    int pL = rsq(left(p), L, (L + R) / 2, i, j);
    int pR = rsq(right(p), (L + R) / 2 + 1, R, i, j);
    
    return pL + pR;
}

void SegmentTree::update(int p, int L, int R, int i, int value) {
    if (L == R) {
        A[i] = st[p] = value;
    } else {
        if (i <= ((L + R) / 2)) update(left(p), L, (L + R) / 2, i, value);
        else update(right(p), (L + R) / 2 + 1, R, i, value);
        st[p] = st[left(p)] + st[right(p)];
    }
}

void SegmentTree::rupdate(int p, int L, int R, int i, int j, int value) {
    if (i > R || j < L) return;
    if (L == R) {
        A[L] = st[p] = value;
    } else {
        rupdate(left(p), L, (L + R) / 2, i, j, value);
        rupdate(right(p), (L + R) / 2 + 1, R, i, j, value);
        st[p] = st[left(p)] + st[right(p)];
    }
}