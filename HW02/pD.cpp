#include <iostream>
using namespace std;

int maze[32][32];

void BFS(int r, int c, int ind) {
    for (int i = r - 1;i <= r + 1;i++) {
        for (int j = c - 1;j <= c + 1; j++) {
            if (i < 0 || j < 0) continue;
            if (i >= 32 || j >= 32) continue;
            if (maze[i][j] == -1) {
                maze[i][j] = ind;
                BFS(i, j, ind);
            }
        }
    }
}

int main() {
    int ind = 1;
    for (int i = 0;i < 32; i++) for (int j = 0;j < 32; j++) {
        cin >> maze[i][j];
        if (maze[i][j] == 1) maze[i][j] = -1;
    }
    for (int i = 0;i < 32; i++) for (int j = 0;j < 32; j++) {
        if (maze[i][j] == -1) {
            BFS(i, j, ind);
            ind++;
        }
    }
    for (int i = 0;i < 32; i++) {
        for (int j = 0;j < 31; j++) {
            cout << maze[i][j] << " ";
        }
        cout << maze[i][31] << endl;
    }
}