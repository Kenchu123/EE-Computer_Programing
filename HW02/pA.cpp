#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
    string s, ss = "";
    getline(cin, s);
    for (int i = 0;i < s.size(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ss += tolower(s[i]);
    }
    // cout << ss << endl;
    bool check = 1;
    for (int i = 0, j = ss.size() - 1; i < j; i++, j--) {
        if (ss[i] != ss[j]) {
            check = 0;
            break;
        }
    }
    if (check) cout << "yes\n";
    else cout << "no\n";
}