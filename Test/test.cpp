// #include <iostream>
// using namespace std;
// void cube_vol_area(int, double, double, double, double*, double*);
// int main( )
// {
// int id=5;
// double s=3, v=10, x=6.3, y=7.2, z=1.5;
// cout<<"cube surface area="<<s<<" cube volume="<<v<<endl;
// cube_vol_area(id, x, y, z, &s, &v);
// cout<<"cube surface area="<<s<<" cube volume="<<v<<endl;
// }
// void cube_vol_area (int id, double width, double length, double height,
// double* surface, double* volume)
// {
// *surface = 2*width*height+2*length*height+2*width*length;
// *volume = width*length*height;
// cout<<"cube surface area="<<*surface<<" cube volume="<<*volume<<endl;
// }

// #include <iostream>
// using namespace std;
// void commute_time (double, double=25, int=5);
// int s = 0;
// int main( )
// {
// commute_time(40);
// commute_time(30, 20);
// commute_time(35, 20, 8);
// cout << s << endl;
// }
// void commute_time(double velocity, double distance, int num_lights)
// {
// cout<<"The commute time is " <<(distance/velocity + num_lights*0.01)
// <<" hours."<<endl;
// s += velocity + distance + num_lights;

// }

// #include <iostream>
// using namespace std;

// int main() {
// 	unsigned int fib[80] = {0, 1, 1};
// 	for (int i = 3; i < 80; i++) {
// 		fib[i] = fib[i - 1] + fib[i - 2];
// 		cout << i << " " << fib[i] << endl;
// 	}


// }

#include <iostream>
using namespace std;
unsigned int fibonacci(int);
int main()
{
int c;
 cin >> c;
cout << "fibonacci( " << c << " ) = "
<< fibonacci(c) << endl;

}
unsigned int fibonacci(int number)
{
if (number <= 1)
return number;
else
return fibonacci(number-1) + fibonacci(number-2);

}