// My student ID: b07901016
#include<iostream>
#include<stdint.h>
#include <math.h>
using namespace std;

int main()
{
    cout<<"|(sin(1.22) - cos(0.08)| = "<< fabs(sin(1.22) - cos(0.08)) << endl;
    cout<<"tanh(0.8)^0.25 + sinh(0.7)^0.15 = "<<  pow(tanh(0.8), 0.25) + pow(sinh(0.7), 0.15) << endl;
	int16_t a = 15761;	// 15761 = 0011 1101 1001 0001  
   	int16_t b = 22349;	// 22349 = 0101 0111 0100 1101
	int16_t c;
	// Please use bitwise operation from a and b to find the answers
	c = a & b;
	cout<<"Decimal value of 0001 0101 0000 0001 = "<< c << endl;
	c = a | b;
	cout<<"Decimal value of 0111 1111 1101 1101 = "<< c << endl;
	c = a ^ b;
	cout<<"Decimal value of 0110 1010 1101 1100 = "<< c << endl;
	c = ~a;
	cout<<"Decimal value of 1100 0010 0110 1110 = "<< c << endl;
	c = a << 2;
	cout<<"Decimal value of 1111 0110 0100 0100 = "<< c << endl;
	c = b >> 2;
	cout<<"Decimal value of 0001010111010011 = "<< c << endl;
 
    return 0;
}
