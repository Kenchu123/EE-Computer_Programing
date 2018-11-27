//PREPEND BEGIN
#include<iostream>

using namespace std;

double** minor_matrix(double **M, int n, int i, int j);
double determinant(double **M, int n, int &count);

int main()
{
    int N;
    cin>>N;
    double** M;
    M = new double*[N];
    for (int i = 0; i < N; ++i){
        M[i] = new double[N];
        for (int j = 0; j < N; ++j)
            cin >> M[i][j];
    }
    int count = 0;
    cout << determinant(M, N, count) << endl;
    cout << count << endl;
    for (int i = 0; i < N; ++i)
        delete[] M[i];
    delete[] M;
    return 0;
}
//PREPEND END

double** minor_matrix(double **M, int n, int i, int j){
    // TODO
    double** mat;
	mat = new double*[n - 1];
    i--; j--;
    
    for (int k = 0;k < n - 1; k++) mat[k] = new double[n - 1];
    bool check_k = 0;
    for (int k = 0;k < n; k++) {
    	if (k == i) {
    		check_k = 1;
    		continue;
		}
    	bool check_w = 0;
    	for (int w = 0;w < n; w++) {
    		if (w == j) {
    			check_w = 1;
    			continue;
			}
    		if (check_k && check_w) {
    			mat[k - 1][w - 1] = M[k][w];
			} 
			else if (check_k) {
				mat[k - 1][w] = M[k][w];
			} else if (check_w) {
				mat[k][w - 1] = M[k][w];
			}
    		else mat[k][w] = M[k][w];
		}
	}
	return mat;
}

double determinant(double **M, int n, int &count){
    // TODO
    count += 1;
    
    if (n == 2) {
    	double tmp = M[0][0] * M[1][1] - M[1][0] * M[0][1];
    	return tmp;
	}
	double tmp = 1;
	double total = 0;
	for (int i = 0;i < n; i++) {
		double** mat = minor_matrix(M, n, 1, i + 1);
		total += M[0][i] * tmp * determinant(mat, n - 1, count);
		tmp = -tmp;
		for (int i = 0; i < n - 1; ++i)
        	delete[] mat[i];
    	delete[] mat;

	}
	return total;
}