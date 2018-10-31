#include <iostream>
using namespace std;

int main() {
	int data_height,data_width;
	int **data = NULL;
	
	cout << "data_height, data_width = ";
	cin >> data_height >> data_width;
	/* 
	TODO
	1: create a dynamic array with dimension height*width
	2: assign value to each array elements
	3: print (cout) out the array, seperate elements in a row with a '\t'
	4: delete the array
	*/
	data = new int*[data_height];
	for (int i = 0;i < data_height; i++) data[i] = new int[data_width];
	for (int i = 0; i< data_height; i++) {
		for (int j = 0; j < data_width; j++) {
			data[i][j] = i * data_width + j;
			cout << data[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < data_height; i++) delete data[i];
	delete [] data;
	return 0;
}
