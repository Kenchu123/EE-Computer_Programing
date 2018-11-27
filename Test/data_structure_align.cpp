#include <iostream>
using namespace std;
struct record {
    char sex;
    int age;
    double height, weight;
};

struct account {
    char id;
    char sex;
    int age;
};
int main( )
{
    record John;
    cout << "size of record: " << sizeof(John) << endl;
    cout << "address of sex: \t " << (void*)&John.sex << endl;
    cout << "address of age: \t " << &John.age << endl;
    cout << "address of height:\t " << &John.height << endl;
    cout << "address of weight:\t " << &John.weight << endl;
    account AC;
    cout << "size of account: " << sizeof(AC) << endl;
    cout << "id\t" << (void*)&AC.id << endl;
    cout << "age\t" << &AC.age << endl;
    cout << "sex\t" << (void*)&AC.sex << endl;
}