#include <iostream>
#include <vector>
using namespace std;

int n, m, q[11], t[11][11], sum;
bool isVisit[11] = {0}; 
vector<int> ans;

bool check() {
    for (int i = 0;i < n; i++) if (isVisit[i] == 0) return 1;
    return 0;
}

void findTheNext(int start, int rest) {
    isVisit[start] = 1;
    int next = -1, nextT = 1e9;
    for (int i = 0;i < n + 1; i++) {
        if (i == start || isVisit[i]) continue;
        if (t[start][i] < nextT && q[i] <= rest) {
            next = i;
            nextT = t[start][i];
        }
    }
    if (next == -1) {
        sum += t[start][0];
        return;
    }
    else {
        sum += t[start][next];
        ans.push_back(next);
        findTheNext(next, rest - q[next]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0;i <= n; i++) for (int j = 0;j <= n; j++) cin >> t[i][j];
    for (int i = 1;i <= n; i++) cin >> q[i];
    while (check()) {
        findTheNext(0, m);
    }
    cout << "Delivery order: ";
    for (int i = 0;i < n - 1; i++) cout << ans[i] << " ";
    cout << ans[n - 1] << "\nTotal time: " << sum << endl;
}