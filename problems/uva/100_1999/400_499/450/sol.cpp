#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define TITLE        0
#define FIRST_NAME   1
#define LAST_NAME    2
#define HOME_ADDRESS 3
#define HOME_PHONE   4
#define WORK_PHONE   5
#define CAMPUS_BOX   6
#define DEPARTMENT   7

typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef pair<int, int> ii;
typedef pair<string, ii> sii;
typedef set<sii> ssii;

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    vvvs departments = vvvs();
    for (int i = 0; i < n; i++) {
        string departmentName;
        vvs department = vvs();
        getline(cin, departmentName);
        while(true) {
            getline(cin, line);
            if (line == "") break;
            vs employee = vs();
            int idx = 0;
            for (int i = 0; i < (int) line.size(); i++) {
                if (line[i] == ',') {
                    employee.push_back(line.substr(idx, i - idx));
                    idx = i + 1;
                } else if (i == (int) line.size() - 1) {
                    employee.push_back(line.substr(idx, i - idx + 1));
                }
            }
            employee.push_back(departmentName);
            department.push_back(employee);
        }
        departments.push_back(department);
    }
    ssii blackBook = ssii();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int) departments[i].size(); j++) {
            sii employee = sii();
            employee.first = departments[i][j][LAST_NAME];
            employee.second = ii(i, j);
            blackBook.insert(employee);
        }
    }
    for (ssii::iterator it = blackBook.begin(); it != blackBook.end(); it++) {
        int i = (*it).second.first;
        int j = (*it).second.second;
        cout << "----------------------------------------" << endl
             << departments[i][j][TITLE] << " "
             << departments[i][j][FIRST_NAME] << " "
             << departments[i][j][LAST_NAME] << endl
             << departments[i][j][HOME_ADDRESS] << endl
             << "Department: " << departments[i][j][DEPARTMENT] << endl
             << "Home Phone: " << departments[i][j][HOME_PHONE] << endl
             << "Work Phone: " << departments[i][j][WORK_PHONE] << endl
             << "Campus Box: " << departments[i][j][CAMPUS_BOX] << endl;
    }
    return 0;
}