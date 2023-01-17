#include <iostream>
using namespace std;
class GrandParent
{
public:
    GrandParent()
    {
        cout << "Inside GrandParent class" << endl;
    }
    string name;
    int age;
};
class Parent :public GrandParent
{
public:
    Parent()
    {
        cout << "Inside Parent class" << endl;
    }
    string college;
    int year;
};
class child :public Parent
{
public:
    child()
    {
        cout << "Inside Child class" << endl;
    }
    int noOfSubject;
    int CGPA;
};
int main()
{
    child c1;
    c1.name = "Nisarg";
    c1.college = "NIT Patna";
    c1.noOfSubject = 5;
    cout << c1.name << endl;
    cout<<c1.college<<endl;
    cout<<c1.noOfSubject<<endl;
}