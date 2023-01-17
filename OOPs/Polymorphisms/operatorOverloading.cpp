// Here we redefined operation of operator.In c++ also that we create user-define function for operator

#include <iostream>
using namespace std;

class A
{
public:
    int a;
    int b;
    void operator+(A &obj)
    {
        int v1 = this->a;
        int v2 = obj.a;
        cout << "Value is " << v2 - v1 << endl;
    }
    void operator()()
    {
        cout << "Mai Bracket hu " << this->a*10<<endl;
    }
    A()
    {
        cout << "Constructor called" << endl;
    }
    ~A()
    {
        cout << "Destructor called" << endl;
    }
};
int main()
{
    A h1,h2;
    h1.a = 15;
    h2.a = 28;
    h2 + h1;
    h2();
}

/*When cursor goes to first line and created two object h1 and h2.
 and cursor goes to next line and assign value object of h1 a is 15 and goes to next line and assign value object of h2,a is 28
 h2+h1 perform. and class A called behalf of h2 and called operator+() of function and assign the address of h1 and further function excute
 */
