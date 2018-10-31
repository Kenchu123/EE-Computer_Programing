// My student ID:b07901016
#include<iostream>
#define R 5
#define C 5
using namespace std;

void printMat(int n, double mat[][C]) {
	for (int i = 0;i < n; i++) {
		for (int j = 0;j < n; j++) cout << mat[i][j] << " ";
		cout << "\n";
	}
}

void transMat(int n, double mat[][C]) {
	int tmp[R][C];
	for (int i = 0;i < n; i++) for (int j = 0;j < n; j++) tmp[i][j] = mat[n - j - 1][i];
	for (int i = 0;i < n; i++) for (int j = 0;j < n; j++) mat[i][j] = tmp[i][j];
}

int main( )
{
	int n;	
	cout << "n = ";
	cin >> n;
	double matrix[R][C];
	for (int i = 0;i < n; i++) for (int j = 0;j < n; j++) cin >> matrix[i][j];
	for (int i = 1;i <= 3; i++) {
		cout << "Angle = " << 90 * i << "�X:\n";
		transMat(n, matrix);
		printMat(n, matrix);
	}
	return 0;
}
