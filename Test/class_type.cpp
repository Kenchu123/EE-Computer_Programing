#include <iostream>
using namespace std;

class A {};

class B {
    public:
        explicit B (const A& x) {}
        B& operator= (const A& x) { return *this; }
        operator A() { return A(); }
};

void fn(B x) {}

int main() {
    A foo;
    B bar(foo);
    bar = foo;
    foo = bar;
    // fn (foo); can't not convert 'foo' from 'A' to 'B'
    // B x = y is invalid
    fn(bar);
}