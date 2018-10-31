#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "This program will convert decimal numbers to base-n system.\nGive me a pair of numbers as follow: DecNumber Base\n";
    int n, d;
    cout << "input: "; 
    while (cin >> n) {
        if (n == 0) break;
        cin >> d;
        string s = "";
        cout << "(" << n << ")_10 = (";
        while (n != 0) {
            int t = n % d;
            n /= d;
            s.push_back(t >= 10 ? char('A' + t - 10) : char('0' + t));
        }
        for (int i = s.length() - 1; i >= 0; i--) cout << s[i];
        cout << ")_" << d << endl;
        cout << "input: ";
    }
}