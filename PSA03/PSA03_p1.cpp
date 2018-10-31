// My student ID:b07901016
#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	cout << "Term\tValue of Pi\n" ;
	double pi = 0;
	double j = 1;
	for (int i = 1; i <= 500; i++) {
		pi += 4 / j;
		j = j > 0 ? -(j + 2) : -(j - 2);
		cout << i << "\t" << fixed << setprecision(5) << pi << endl;
	}
	return 0;
}

