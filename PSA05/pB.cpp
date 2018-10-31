#include <iostream>
using namespace std;

void henata (int num, int left, int mid, int right) {
    if (num < 1) {
        return;
    }
    henata(num - 1, left, right, mid);
    cout << left << " -> " << right << endl;
    henata(num - 1, mid, left, right);

}

int main() {
    int n;
    cin >> n;
    henata(n, 1, 2, 3);
}