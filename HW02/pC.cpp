#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n, l, ind;
vector<int> ls;
vector< pair<int, int> > num[1024]; //index, length

int main() {
    cin >> n;
    string s;
    for (int i = 0;i < n; i++) {
        cin >> l;
        ls.push_back(l);
        string ss;
        for (int j = 0;j < l; j++) {
            cin >> ss;
            num[i].push_back(make_pair(s.length(), ss.size()));
            s += ss;
        }
    }
    int task;
    cin >> task;
    for (int i = 0; i < task; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        swap(num[a][b], num[c][d]);
    }
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < ls[i] - 1; j++) {
            if (num[i][j].second > 0) cout << s.substr(num[i][j].first, num[i][j].second) << " ";
        }
        cout << s.substr(num[i][ls[i] - 1].first, num[i][ls[i] - 1].second);
        cout << endl;
    }
}