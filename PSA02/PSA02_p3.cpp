// My student ID: b07901016
#include<iostream>
using namespace std;

int main()
{
	int x;
	cout << "input:";
	cin >> x;
	if (x >= 0 && x <= 31 || x == 127) {
		cout << "It's a control char.\n"; 
	}
	else if (x > 31 && x < 127) {
		cout << (char)x << endl;
	}
	else cout << "Input Error!\n";
	return 0;
}
