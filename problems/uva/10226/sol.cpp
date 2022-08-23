#include <cstdio>
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    string tree;
    getline(cin, tree);
    getline(cin, tree);
    for (int TC = 0; TC < t; TC++) {
        if (TC) printf("\n");
        int n = 0;
        map<string, int> trees;
        while(true) {
            getline(cin, tree);
            if (tree == "") break;
            n++;
            if (trees.find(tree) == trees.end()) {
                trees[tree] = 1;
            } else {
                trees[tree]++;
            }
        }
        map<string, int>::iterator it = trees.begin();
        while(it != trees.end()) {
            cout << it->first;
            printf(" %.4f\n", (double) it->second / (double) n * 100.0);
            it++;
        }
    }
    return 0;
}