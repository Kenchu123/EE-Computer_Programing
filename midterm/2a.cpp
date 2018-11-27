#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0;i < s.size(); i++) {
		s[i] = ::toupper(s[i]);
	}
	cout << s << endl;
}