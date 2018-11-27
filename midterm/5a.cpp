//PREPEND BEGIN
#include<iostream>

using namespace std;

double** minor_matrix(double **M, int n, int i, int j);

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
    int i, j;
    cin >> i >> j;
    double** min = minor_matrix(M, N, i, j);
    for (int i = 0; i < N-1; ++i){
        for (int j = 0; j < N-2; ++j)
            cout << min[i][j] << " ";
        cout << min[i][N-2] << endl;
    }
    for (int i = 0; i < N; ++i)
        delete[] M[i];
    delete[] M;
    for (int i = 0; i < N-1; ++i)
        delete[] min[i];
    delete[] min;
    return 0;
}
//PREPEND END

//TEMPLATE BEGIN
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
//TEMPLATE END