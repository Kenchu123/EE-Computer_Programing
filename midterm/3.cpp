#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

int _stoi(string s) {
	int tmp = 0;
	for (int i = 0; i < s.size(); i++) {
		tmp += (s[i] - '0') * pow(10, s.size() - i - 1);
	}
	return tmp;
}

string _itos(int num) {
	if(num == 0) return "0";
	string tmp, re;
	while (num != 0) {
		tmp += char(num % 10 + '0');
		num /= 10;
	}
	for (int i = tmp.size() - 1; i >= 0; i--) re += tmp[i];
	return re;
}

int _ctoi(char a) {
	return a - '0';
}

int main() {
	vector<string> output;
	vector<int> w;
	string a, b;
	cin >> a >> b;
	int num_a = _stoi(a);
	int num_b = _stoi(b);
	string total = _itos(num_a * num_b);
	int len = total.size() + 1;
	string f = "", s = "x";
	for (int i = 0;i < len - a.size(); i++) {
		f += ' ';
	}
	f += a;
	output.push_back(f);
	w.push_back(len);
	for (int i = 0; i < len - b.size() - 1; i++) {
		s += ' ';
	}
	s += b;
	output.push_back(s);
	w.push_back(len);
	string dash = "";
	for (int i = 0;i < len; i++) dash += '-';
	output.push_back(dash);
	w.push_back(len);
	int ind = len;
	string tmp = "";
	for (int i = b.size() - 1;i >= 0; i--) {
		int de = _ctoi(b[i]);
		int pro = de * num_a;
		string s_pro = _itos(pro);
		if (s_pro.size() == 1) {
			tmp += s_pro[0];
			continue;
		}
		if (tmp.size() != 0) {
			string t2 = "";
			for (int i = tmp.size() - 1; i >= 0; i--) t2 += tmp[i];
			s_pro += t2;
			tmp = "";
		}
		output.push_back(s_pro);
		w.push_back(ind);
		ind--;
	}
	if (tmp.size() != 0) {
		string t2 = "";
		for (int i = tmp.size() - 1; i >= 0; i--) t2 += tmp[i];
		output.push_back(t2);
		w.push_back(ind);
	}
	if (output.size() > 4) {
		output.push_back(dash);
		output.push_back(total);
		w.push_back(len);
		w.push_back(len);
	}
	for (int i = 0;i < output.size(); i++) cout << setw(w[i]) << output[i] << endl;
	
}
