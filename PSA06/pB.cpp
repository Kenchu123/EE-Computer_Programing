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
    if (n < 0) return 0;
    for (int i = 1;i <= 3; i++) {
        ans[index++] = i;
        num_of_ways(n - i);
        index -= 1;
    }
    if (n == 0) {
        for (int i = 0; i < index - 1; i++) cout << ans[i] << " ";
        cout << ans[index - 1] << "\n" << index << endl;
        total += 1;
    }
    return total;
}