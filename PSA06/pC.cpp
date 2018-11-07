//PREPEND BEGIN
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;
//PREPEND END

//TEMPLATE BEGIN
uint64_t bus_exp(uint64_t* arr, double p, time_t run_time){
    // TODO
    time_t _t = time(0);
    uint64_t cnt = 0;
    while (time(0) - _t < run_time) {
        cnt++;
        for (int i = 0;i < 60; i++) {
            double _p = (double) rand() / RAND_MAX;
            if (_p <= p) {
                arr[i] += 1;
                break;
            }
        }
    }
    return cnt;
}
//TEMPLATE END

//APPEND BEGIN
int main()
{   
    srand(0);
    time_t run_time; // experiment running time, unit: seconds
    double p;        // probability of Bernoulli distribution
    uint64_t _count; // counting experiment executions

    uint64_t data[60] = {0};
    cout << "Please Enter execution time and prob:\n";
    cin >> run_time >> p;

    time_t _t = time(0);
    _count = bus_exp(data, p, run_time);
    _t = time(0) - _t;
    if( (run_time - _t) < 2 && (_t - run_time) < 2)
        cout << "Correct execution time!\n";
    else cout << "Wrong execution time!\n";

    cout << "Distribution: \n";
    for(int i = 0; i < 60 ; ++i)
        cout << fixed << setprecision(2) << ((double)data[i] / (double)_count) << (i%10 == 9?'\n':' ');

    uint64_t _sum = 0;
    for(int i = 0; i < 60 ; ++i)
        _sum += data[i] * (i+1);
    cout << "Expectation value: " << fixed << setprecision(2) << ((double)_sum)/((double)_count) << endl;

    cout.flush();

    return 0;
}
//APPEND END
