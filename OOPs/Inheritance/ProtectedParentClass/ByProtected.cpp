#include <iostream>
using namespace std;
//Resultant in form of protected
class Human
{
protected:

    string name;
    int height;
    int age;

public:
    Human()
    {
        cout << "Default constructor of Parent class called" << endl;
    }
};
class Man : protected Human
{
public:
    string strOfSex;
    string color;

public:
    Man(string t)
    {
        this->color = t;
        cout << "Parameterised  constructor of child class called" << endl;
    };

    Man()
    {
        cout << "Default constructor of child class called" << endl;
    }
};
int main()
{
    Man m1;
    cout << m1.name << endl;
    cout << m1.age << endl;
    cout << m1.height << endl;
    cout << m1.strOfSex << endl;

    m1.name = "Nisarg Patel";
    m1.age = 19;
    m1.height = 175;
    m1.strOfSex = "Male";
    cout << m1.name << endl;
    cout << m1.age << endl;
    cout << m1.height << endl;
    cout << m1.strOfSex << endl;
}