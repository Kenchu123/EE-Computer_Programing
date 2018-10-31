#include <iostream>
#include <algorithm>
using namespace std;

int num[10];

int main() {
	
	cout << "Please enter 10 integers:" << endl;
	for (int i = 0;i < 10; i++) cin >> num[i];
	// Sort the 10 input integers
	// sort(num, num + 10);
	for (int i = 0;i < 10; i++) for (int j = 0; j < 10 - i - 1; j++) if (num[j] > num[j + 1]) {
		int tmp = num[j];
		num[j] = num[j + 1];
		num[j + 1] = tmp;
	}
	cout << "The sorting result is:" << endl;
	for (int i = 0;i < 9; i++) cout << num[i] << " ";
	cout << num[9] << endl;
	return 0;
}
