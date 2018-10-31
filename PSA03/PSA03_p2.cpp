// My student ID:b07901016
#include<iostream>
#include <string>
using namespace std;

int main( )
{
	int fib[41] = {0, 1, 1};
	for (int i = 3; i <= 40; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while(1) {
		int n = 0;	
		cout << "n = ";
		string s;
		cin >> s;
		bool invalid = 0;
		if (s.length() > 2) invalid = 1;
		for (int i = 0;i < s.length(); i++) {
			if (s[i] > '9' || s[i] < '0') invalid = 1;
		}
		if (s[0] == '0') invalid = 1;
		if (!invalid) n = stoi(s, nullptr);
		if (n > 40 || n < 1) invalid = 1;
		if (invalid) {
			cout << "Illegal Input! Please enter an integer in the range [1, 40].\n";
			continue;
		}
		cout << "The first " << n << " elements of the Fibonacci sequence are:" << endl;
		for (int i = 1;i < n;i++) cout << fib[i] << ", ";
		cout << fib[n] << endl;
	}

	return 0;
}
