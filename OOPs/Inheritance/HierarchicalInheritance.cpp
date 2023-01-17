#include<iostream>
using namespace std;
class A
{
    public:
    void funA()
    {
        cout << "Inside function A" << endl;
    }
    A(){
        cout << "Constructor of A called" << endl;
    }
};
class B:public A
{
    public:
    void funB()
    {
        cout << "Inside function B" << endl;
    }
    B(){
        cout << "Constructor of B called" << endl;
    }
};
class C :public A
{
    public :
    void funC()
    {
        cout << "Inside function C" << endl;
    }
    C(){
        cout << "Constructor of C called" << endl;
    }
};
int main()
{
    B obj1;
    C obj2;
    obj1.funA();
    obj1.funB();
    obj2.funA();
}