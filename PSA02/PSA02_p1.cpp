// My student ID: b07901016
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{	
	double a, b, c;
	int prec;
	cout <<"Please enter three numbers:"  << endl;
	cin >> a >> b >> c;
	cout <<"Please enter the output precision:"  << endl;	
	cin >> prec;
	cout <<"average = ";
	cout << fixed << setprecision(prec) << (a + b + c) / 3 << endl;
	return 0;
}
