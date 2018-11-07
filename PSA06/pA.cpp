//PREPEND BEGIN
#include<iostream>
#include<iomanip>

using namespace std;
//PREPEND END

//TEMPLATE BEGIN
double my_max(double a[], int length = 2){
    // TODO
    double m = a[0];
    for (int i = 0;i < length; i++) m = m > a[i] ? m : a[i];
    return m;
}

double my_max(double a[], double b[], int length_a = 2, int length_b = 2){
    // TODO
    double m_a = a[0], m_b = b[0];
    for (int i = 0;i < length_a; i++) m_a = m_a > a[i] ? m_a : a[i];
    for (int i = 0;i < length_b; i++) m_b = m_b > b[i] ? m_b : b[i];
    return m_a > m_b ? m_a : m_b;
}

//TEMPLATE END

//APPEND BEGIN
int main(){
    int N_a, N_b;

    cout << "Please Enter length of a and b:" << endl;
    cin >> N_a >> N_b;

    double *a = new double[N_a];
    double *b = new double[N_b];

    cout << "Please elements of a:" << endl;
    for(int i = 0; i < N_a ; ++i)
        cin >> a[i];
    cout << "Please elements of b:" << endl;
    for(int i = 0; i < N_b ; ++i)
        cin >> b[i];

    cout << "Maximum in a1 and a2: ";
    cout << fixed << setprecision(2) << my_max(a) << endl;
    cout << "Maximum in b1 and b2: ";
    cout << fixed << setprecision(2) << my_max(b) << endl;
    cout << "Maximum in array a: ";
    cout << fixed << setprecision(2) << my_max(a, N_a) << endl;
    cout << "Maximum in array b: ";
    cout << fixed << setprecision(2) << my_max(b, N_b) << endl;
    cout << "Maximum in array a and array b: ";
    cout << fixed << setprecision(2) << my_max(a, b, N_a, N_b) << endl;

    delete [] a;
    delete [] b;

    return 0;
}
//APPEND END