#include <iostream>
using namespace std;

enum Jizz {
    hello, world, jizz
};

union mix {int i; double f; unsigned char c[8];};

int main() {
    Jizz a = hello;
    Jizz b = world;
    Jizz c = jizz;
    cout << a << b << c << endl;
    mix x;
    x.f = 2018.1127;
    cout << "sizeof(x): " << sizeof(x) << endl;
    for (int i=7;i>=0;i--) cout << hex << (int)x.c[i];
    cout << endl;
}