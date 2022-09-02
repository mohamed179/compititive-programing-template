#include <iostream>
#include <map>
using namespace std;

#define DOMINANT "dominant"
#define RECESSIVE "recessive"
#define NONEXISTENT "non-existent"

typedef pair<int, string> is;
typedef pair<string, string> ss;
typedef pair<string, ss> sss;
typedef map<string, sss> msss;

int main() {
    int n, calculated = 0;
    cin >> n;
    msss people;
    for (int i = 0; i < n; i++) {
        string str1, str2;
        cin >> str1 >> str2;
        if (str2 == DOMINANT || str2 == RECESSIVE || str2 == NONEXISTENT) {
            people[str1] = sss(str2, ss("", ""));
            calculated++;
        } else if (people.find(str2) == people.end()) {
            people[str2] = sss("", ss(str1, ""));
        } else {
            people[str2].second.second = str1;
        }
    }
    int total = people.size();
    while (calculated < total) {
        for (msss::iterator it = people.begin(); it != people.end(); it++) {
            if (it->second.first == "") {
                string parent1 = it->second.second.first;
                string parent2 = it->second.second.second;
                if (parent1 != "" && people[parent1].first != "" && people[parent2].first != "") {
                    calculated++;
                    string parent1_status = people[parent1].first;
                    string parent2_status = people[parent2].first;
                    if ((parent1_status == DOMINANT && parent2_status == DOMINANT) ||
                        (parent1_status == DOMINANT && parent2_status == RECESSIVE) ||
                        (parent1_status == RECESSIVE && parent2_status == DOMINANT)) {
                        it->second.first = DOMINANT;
                    } else if ((parent1_status == DOMINANT && parent2_status == NONEXISTENT) ||
                               (parent1_status == NONEXISTENT && parent2_status == DOMINANT) ||
                               (parent1_status == RECESSIVE && parent2_status == RECESSIVE)) {
                        it->second.first = RECESSIVE;
                    } else {
                        it->second.first = NONEXISTENT;
                    }
                }
            }
        }
    }
    for (msss::iterator it = people.begin(); it != people.end(); it++) {
        cout << it->first << " " << it->second.first << endl;
    }
    return 0;
}