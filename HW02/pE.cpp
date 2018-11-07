#include <iostream>
using namespace std;

int finalr = 4, finalc = 11;
int dir = 1; // 0 down, 1 right, 2, up, 3 left

bool maze[10][12] = {
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,1,0,1,0,1,0,1},
    {1,1,1,0,1,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,1,1,1,1,0,1},
    {1,1,0,1,1,1,1,1,1,1,0,0},
    {1,1,0,1,0,1,1,1,1,1,1,1},
    {1,1,0,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1,1,0,1,0,1},
    {1,1,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}
};

bool checkUp (int& r, int& c) {
    if (maze[r - 1][c]) return 0;
    r -= 1;
    return 1;
}
bool checkDown (int& r, int& c) {
    if (maze[r + 1][c]) return 0;
    r += 1;
    return 1;
}
bool checkLeft (int& r, int& c) {
    if (maze[r][c - 1]) return 0;
    c -= 1;
    return 1;
}
bool checkRight (int& r, int& c) {
    if (maze[r][c + 1]) return 0;
    c += 1;
    return 1;
}

bool check(int& r, int& c, int d) {
    if (d == 0) return checkDown(r, c);
    if (d == 1) return checkRight(r, c);
    if (d == 2) return checkUp(r, c);
    if (d == 3) return checkLeft(r, c);
}

int main() {
    int r, c;
    while (cin >> r >> c) {
        if (maze[r][c] == 0) break;
        cout << "Invalid start!\n";
    }
    cout << r << " " << c << endl;
    while (r != finalr || c != finalc) {
        if (check(r, c, dir - 1 < 0 ? 3 : dir - 1)) {
            dir = dir - 1 < 0 ? 3 : dir - 1;
            cout << r << " " << c << endl;
        }
        else if (check(r, c, dir)) {
            cout << r << " " << c << endl;
        }
        else if (check(r, c, dir + 1 > 3 ? 0 : dir + 1)) {
            dir = dir + 1 > 3 ? 0 : dir + 1;
            cout << r << " " << c << endl;
        } 
        else {
            check(r, c, dir + 2 > 3 ? dir - 2 : dir + 2);
            dir = dir + 2 > 3 ? dir - 2 : dir + 2;
            cout << r << " " << c << endl;
        }
    }
}