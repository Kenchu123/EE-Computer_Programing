#include <iostream>
#define W 10000000
using namespace std;

int n, m;
int ls[1024];
char *s, *s_ptr;
char **w_ptr[1024];

int main() {
    s = new char[W];
    s_ptr = s;
    cin >> n;
    for (int i = 0;i < n; i++) {
        cin >> ls[i];
        w_ptr[i] = new char*[ls[i]];
        for (int j = 0;j < ls[i]; j++) {
            w_ptr[i][j] = s_ptr;
            char tmp[1024]; cin >> tmp;
            int k = 0;
            do {
                s_ptr[0] = tmp[k];
                s_ptr++, k++;
            } while (tmp[k] != '\0');
            s_ptr++;
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
        for (int j = 0;j < ls[i] - 1; j++) {
            cout << w_ptr[i][j] << " ";
        }
        cout << w_ptr[i][ls[i] - 1] << endl;
    }
}