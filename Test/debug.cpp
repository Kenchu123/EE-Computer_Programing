#include<iostream>
#include <vector>
using namespace std;
static int num_of_ways(int);
int main()
{
  int n;
  cin >> n;
  cout << num_of_ways(n) << endl;
}
int num_of_ways(int n){
  //todo
    static int index = 0, total = 0, ans[15] = {0};
    if (n >= 1) {
        cout << 1 << " ";
        num_of_ways(n - 1);
    }
    if (n >= 2) {
        cout << 2 << " ";
        num_of_ways(n - 2);
    }
    if (n >= 3) {
        cout << 3 << " ";
        num_of_ways(n - 3);
    }
    if (n == 0) {
        // for (int i = 0; i < index - 1; i++) cout << ans[i] << " ";
        // cout << ans[index - 1] << "\n" << index << endl;
        cout << endl;
        total += 1;
    }
    return total;
}