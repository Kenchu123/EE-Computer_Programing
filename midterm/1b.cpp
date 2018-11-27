#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string binary1 = "", binary2 = "";

void cal(long long num, string& binary) {
	num = abs(num);
	while (num != 0) {
		binary += char('0' + num % 2);
		num /= 2;
	}
	for (int i = binary.size(); i < 32; i++) {
		binary += '0';
	}
}

void reverse(int num, string& binary) {
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
	long long int a, b;
	cin >> a >> b;
	cal(a, binary1);
	cal(b, binary2);
	if (a < 0) {
		reverse(a, binary1);
	}
	if (b < 0) {
		reverse(b, binary2);
	}
//	for (int i = 31; i >= 0; i--) cout << binary1[i];
//	cout << endl;
//	for (int i = 31; i >= 0; i--) cout << binary2[i];
//	cout << endl;
	int cnt = 0;
	for (int i = 0;i < 32; i++) {
		if (binary1[i] != binary2[i]) cnt++;
	}
	cout << cnt << endl;
}