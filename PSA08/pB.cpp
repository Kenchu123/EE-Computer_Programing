//PREPEND BEGIN
#include <iostream>
#include <string>
using namespace std;
//PREPEND END
//TEMPLATE BEGIN
class Polynomial{
  public:
  //add any member function as you like.
  void init(int coefficient[], int n){
    //todo
    deg = n;
    num = new int[n];
    for (int i = 0;i < n; i++) num[i] = coefficient[i];
  }
  void print(){
    //todo
    for (int i = deg - 1;i >= 0; i--) {
        if (num[i] == 0) continue;
        if (num[i] > 0) cout << "+";
        if (i == 0) cout << num[i];
        else if (i == 1) cout << num[i] << "x";
        else cout << num[i] << "x^" << i;
    }
    cout << endl;
  }

  Polynomial add(Polynomial *poly2){
    //todo
    Polynomial p_max, p_min, tmp;
    if (this->deg > poly2->deg) p_max = *this, p_min = *poly2;
    else p_max = *poly2, p_min = *this;

    int* _n = new int [p_max.deg];
    for (int i = 0;i < p_min.deg; i++) _n[i] = p_max.num[i] + p_min.num[i];
    for (int i = p_min.deg; i < p_max.deg; i++) _n[i] = p_max.num[i];
    tmp.init(_n, p_max.deg);
    return tmp;
  }

  Polynomial multiply(Polynomial *poly2){
    //todo
    Polynomial p_max, p_min, tmp;
    if (this->deg > poly2->deg) p_max = *this, p_min = *poly2;
    else p_max = *poly2, p_min = *this;

    int new_deg = p_max.deg + p_min.deg - 1;
    int* new_num = new int [new_deg];
    for (int i = 0;i < new_deg; i++) new_num[i] = 0;
    for (int i = 0;i < p_min.deg; i++) {
        for (int j = 0;j < p_max.deg; j++) {
            new_num[i + j] += p_min.num[i] * p_max.num[j];
        }
    }
    tmp.init(new_num, new_deg);
    return tmp;
  }

private:
  //add any member variable as you like.
  int deg, *num;

};
//TEMPLATE END
//APPEND BEGIN
void test() {
    int n, m;
    int cmds, cmd, pid, pid2;
    int v[4096];
    cin >> n;
    Polynomial *p = new Polynomial[n];
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++)
            cin >> v[j];
        p[i].init(v, m);
    }
    cin >> cmds;
    for (int i = 0; i < cmds; i++) {
        cin >> cmd >> pid;
        if (cmd == 1) {
            p[pid].print();
        } else if (cmd == 2) {
            cin >> pid2;
            Polynomial ret = p[pid].add(&p[pid2]);
            ret.print();
        } else if (cmd == 3) {
            cin >> pid2;
            Polynomial ret = p[pid].multiply(&p[pid2]);
            ret.print();
        }
    }
}
int main() {
    test();
    return 0;
}
//APPEND END