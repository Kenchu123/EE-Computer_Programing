#include <iostream>
#include <cmath>
#define eps 1e-14
using namespace std;

char f1(double x, double y) { //4y−x^2+8 
    if (fabs(x - (int)x) < eps && y == 0) return '0' + abs(int(x));
    if (fabs(y - (int)y) < eps && x == 0) return '0' + abs(int(y));
    double tmp = 4 * y - pow(x, 2) + 8;
    if (tmp >= 0) return '+';
    else return '-';
}

char f2(double x, double y) { //8y^2+x^2-40
    if (fabs(x - (int)x) < eps && y == 0) return '0' + abs(int(x));
    if (fabs(y - (int)y) < eps && x == 0) return '0' + abs(int(y));
    double tmp = 8 * pow(y, 2) + pow(x, 2) - 40;
    if (tmp >= 0) return '+';
    else return '-';
}

char f3(double x, double y) { //(x^2+3y^2-10)^3-50x^2*y^3
    if (fabs(x - (int)x) < eps && y == 0) return '0' + abs(int(x));
    if (fabs(y - (int)y) < eps && x == 0) return '0' + abs(int(y));
    double tmp = pow(pow(x, 2) + 3 * pow(y, 2) - 10, 3) - 50 * pow(x, 2) * pow(y, 3);
    if (tmp >= 0) return '+';
    else return '-';
}
int main() {
    cout << "f(x, y) = 4y−x^2+8:\n";
    for (double y = 4; y >= -4; y -= 0.5) {
        for (double x = -8; x <= 8; x += 0.25) {
            cout << f1(x, y);
        }
        cout << "\n";
    }
    cout << endl;
    cout << "f(x, y) = 8y^2+x^2-40:\n";
    for (double y = 4; y >= -4; y -= 0.5) {
        for (double x = -8; x <= 8; x += 0.25) {
            cout << f2(x, y);
        }
        cout << "\n";
    }
    cout << endl;
    cout << "f(x, y) = (x^2+3y^2-10)^3-50x^2*y^3:\n";
    for (double y = 4; y >= -4; y -= 0.5) {
        for (double x = -8; x <= 8; x += 0.25) {
            cout << f3(x, y);
        }
        cout << "\n";
    }
}