// #include <iostream>
// #include <ctime>
// using namespace std;

// int main() {
//     int fib[40] = {0, 1, 1};
//     clock_t t = clock();
//     for (int i = 3;i <= 10; i++) fib[i] = fib[i - 1] + fib[i - 2];
//     // cout << fib[10] << endl;
//     t = clock() - t;
//     cout << ((float)t) / CLOCKS_PER_SEC;
// }

// #include <iostream>
// #include <ctime>
// using namespace std;
// unsigned long fibonacci(int);
// int main()
// {
//     clock_t t = clock();
// for (int c = 0; c <= 10; c++)
//     cout << "fibonacci( " << c << " ) = "
//     << fibonacci(c) << endl;
//     t = clock() - t;
//     cout << ((float)t) / CLOCKS_PER_SEC;

// }
// unsigned long fibonacci(int number)
// {
//     if (number <= 1)
//     return number;
//     else
//     return fibonacci(number-1) + fibonacci(number-2);

// }

#include <iostream>
#include <ctime>
using namespace std;
unsigned long fibonacci(int number)
{
    if (number == 0) return 0;
    unsigned long u=0, v=1, t;
    for (int i=2; i<=number; i++)
    {
        t = u + v;
        u = v;
        v = t;
    }
    return v;
}
int main()
{   
    clock_t t = clock();
    for (int c = 0; c <= 10; c++)
    cout << "fibonacci( " << c << " ) = " << fibonacci(c) << endl;
    t = clock() - t;
    cout << ((float)t) / CLOCKS_PER_SEC << endl;
}