#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
	string s, k;
	cin >> s >> k;
	for (int i = 0;i < s.size(); i++) {
		s[i] = ::toupper(s[i]);
	}
	for (int i = 0;i < k.size(); i++) {
		k[i] = ::toupper(k[i]);
	}
	int ks = k.size();
	for (int i = k.size(), p = 0; i < s.size(); i++, p++) {
		k += k[p];
	}
	for (int i = 0;i < s.size(); i++) {
		s[i] = char(s[i] + k[i] - 'A');
		if (s[i] > 'Z') s[i] = char(s[i] - 26);
	}
	cout << s << endl;
}