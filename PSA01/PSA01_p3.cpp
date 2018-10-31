// My student ID: b07901016
#include<iostream>
using namespace std;

int main()
{
	// Output: deCodedMessage

	char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14;
	int i = 23; //TODO (find out the value of i)
	c1 = 'M' + i; // TODO (fill in a character)
	c2 = 78 + i;
	c3 = ',' + i; // TODO (fill in a character)
	c4 = 88 + i; // TODO (replace _num with a decimal number)
	c5 = 77 + i; // TODO (replace _num with a decimal number)
	c6 = 'N' + i; 
	c7 = '\x4D' + i; // TODO (in the format of hex)
	c8 = '6' + i; // TODO (fill in a character)
	c9 = '\116' + i;
	c10 = '\\' + i; // TODO (fill in a character)
	c11 = '\\' + i;
	c12 = 'J' + i;
	c13 = 'P' + i; // TODO (fill in a character)
	c14 = '\x4E' + i;
	
	cout << c1 << c2 <<c3 << c4 << c5 << c6 << c7 << c8
		 << c9 << c10 << c11 << c12 << c13 << c14 << endl;
		 
	return 0;
}
