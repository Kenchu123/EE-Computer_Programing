// My student ID: b07901016
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int a = 777;
	double b = 3.14159;
	
	/* 
	Required output
	####################################################
	#             Value of A: 777                      #
	# Hexadecimal value of A: 309                      #
	#       Octal value of A: 1411                     #
	#             Value of B: 3.14                     #
	####################################################
	*/
	
	cout << "####################################################" << endl;
	cout << "#" << setw(25) << "Value of A: " << a << setw(23) << "#" << endl;
	cout << "#" << setw(25) << "Hexadecimal value of A: " << hex << a << setw(23) <<  "#" << endl;
	cout << "#" << setw(25) << "Octal value of A: " << oct << a << setw(22) << "#" << endl;
	cout << "#" << setw(25) << "Value of B: " << setprecision(3) << b << setw(22) << "#" << endl;
	cout << "####################################################" << endl;
	
	return 0;
}

