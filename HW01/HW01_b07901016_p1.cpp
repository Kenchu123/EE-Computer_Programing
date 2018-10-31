#include <iostream>
#include <algorithm>
using namespace std;

bool check(int n, int d) {
    if (n % d == 0) return 1;
    while (n != 0) {
        int tmp = n % 10;
        if (tmp == d) return 1;
        n /= 10;
    }
    return 0;
}

int main() {
    int n, d;
    cout << "Total number n = ";
    cin >> n;
    cout << "Code d = ";
    cin >> d;
    for (int i = 1;i < n; i++) {
        if (check(i, d)) cout << "*,";
        else cout << i << ",";
    }
    if (check(n, d)) cout << "*\n";
    else cout << n << "\n";
}