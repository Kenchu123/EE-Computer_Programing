//PREPEND BEGIN
#include<iostream>
using namespace std;

enum data_type {character=1, integer, float_number};
union data {char c; int i; float f;};
//PREPEND END

//TEMPLATE BEGIN
int main()
{
    data_type t;
    data x;
    int input;
    // Enter 1 for character, 2 for integer, 3 for float number
    while((cin >> input)&&(input>=1)&&(input<=3)) {
        t = (data_type)input;
        data d;
        switch(t) {
            case character:
              //todo
              cin >> d.c;
              cout << "data = character: " << d.c << endl;
              break;
            case integer:
              //todo
              cin >> d.i;
              cout << "data = integer: " << d.i << endl;
              break;
            case float_number:
              //todo
              cin >> d.f;
              cout << "data = float_number: " << d.f << endl;
              break;
        }
    }
    return 0;
}
//TEMPLATE END
