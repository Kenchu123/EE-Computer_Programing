#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string binary = "";

void cal(long long num) {
	num = abs(num);
	while (num != 0) {
		binary += char('0' + num % 2);
		num /= 2;
	}
	for (int i = binary.size(); i < 32; i++) {
		binary += '0';
	}
}

void reverse(int num) {
	int ind = 0;
	for (ind = 0; ind < 32; ind++) {
		if (binary[ind] == '1') break;
	}
	ind += 1;
	for (ind; ind < 32; ind++) {
		if (binary[ind] == '1') binary[ind] = '0';
		else binary[ind] = '1';
	}
}

int main() {
	long long int num;
	cin >> num;
	cal(num);
	if (num < 0) {
		reverse(num);
	}
	for (int i = 31; i >= 0; i--) cout << binary[i];
	cout << endl;
}