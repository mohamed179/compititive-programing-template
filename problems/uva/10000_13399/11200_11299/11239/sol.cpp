#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef set<int> si;
typedef map<string, si> ssi;
typedef set<string> ss;
typedef map<string, ss> sss;
typedef pair<int, string> is;
typedef vector<is> vis;

void calculate(ssi students, sss projects);

int main() {
    ssi students;
    sss projects;
    string currentProject;
    int n = 0;
    while(true) {
        string line;
        getline(cin, line);
        if (line == "1") {
            calculate(students, projects);
            students = ssi();
            projects = sss();
            n = 0;
        } else if (line == "0") {
            calculate(students, projects);
            break;
        } else {
            if (line[0] >= 'A' && line[0] <= 'Z') {
                currentProject = line;
                projects[currentProject] = ss();
                n++;
            } else {
                projects[currentProject].insert(line);
                if (students.find(line) == students.end()) {
                    students[line] = si();
                }
                students[line].insert(n);
            }
        }
    }
    return 0;
}

void calculate(ssi students, sss projects) {
    for (sss::iterator sss_it = projects.begin(); sss_it != projects.end(); sss_it++) {
        for (ss::iterator ss_it = sss_it->second.begin(); ss_it != sss_it->second.end(); ) {
            if (students[*ss_it].size() > 1) {
                ss_it = sss_it->second.erase(ss_it);
            } else {
                ss_it++;
            }
        }
    }
    vis ans = vis();
    for (sss::iterator sss_it = projects.begin(); sss_it != projects.end(); sss_it++) {
        ans.push_back(is(- (int) sss_it->second.size(), sss_it->first));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].second << " " << (- ans[i].first) << endl;
    }
}