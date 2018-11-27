#include <iostream>
#define W 10000000
using namespace std;

int n, m;
int *ls;
char *s, *s_ptr;
char ***w_ptr;

int main() {
    s = new char[W];
    s_ptr = s;
    cin >> n;
    w_ptr = new char** [n];
    ls = new int[n];
    for (int i = 0;i < n; i++) {
        cin >> ls[i];
        w_ptr[i] = new char*[ls[i]];
        for (int j = 0;j < ls[i]; j++) {
			w_ptr[i][j] = new char[1024];
            // w_ptr[i][j] = s_ptr;
            // cin >> s_ptr;
            // while (s_ptr[0] != '\0') s_ptr++;
            // s_ptr++;
			cin >> w_ptr[i][j];
        }
    }
    cin >> m;
    for (int i = 0;i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        char* tmp = w_ptr[x1][y1];
        w_ptr[x1][y1] = w_ptr[x2][y2];
        w_ptr[x2][y2] = tmp;
    }
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < ls[i]; j++) {
            cout << w_ptr[i][j] << (j == ls[i] - 1 ? '\n' : ' ');
        }
    }
    for (int i = 0;i < n; i++) delete [] w_ptr[i];
    delete w_ptr;
    delete [] ls;
    delete [] s;
}