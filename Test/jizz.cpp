#include <iostream>
#include "header.hpp"
using namespace std;

int& max(int n1, int n2) {
	if (n1 > n2) return n1;
	return n2;
}

int main() {
	int x = 3, y = 2;
	cout << max(x, y) << endl;
	max(x, y) = 5;
	cout << x << " " << y << endl;
}