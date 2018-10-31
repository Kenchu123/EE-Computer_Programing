#include <iostream>
#include <iomanip>
using namespace std;

//44FC4346
//C4A42A05
int main( )
{
	// unsigned char a[4] = {0x00, 0x2A, 0xA4, 0xC4};
	unsigned char a[4] = {0x05, 0x2A, 0xA4, 0xC4};
	void *p = a;
	cout << *(float*)p << endl;
	cout << "floating value=" << setprecision(8) << *(float*)p << endl;
	float x = -1313.3131;
	p = &x;
	cout << "byte sequence=";
	for (int i=3;i>=0;i--)
	cout << hex << uppercase << (int)( (unsigned char*)p )[i] << ' ';
	// cout << endl;
	// char g = 'g';
	// cout << g << endl;
	// cout << &g << endl;
	// cout << (int*)&g << endl;
}


//52
// 2018.1023
// C4A42A05
// 702601
