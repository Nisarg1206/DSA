// Polymorphism in run time(https://www.geeksforgeeks.org/cpp-polymorphism/)
//fir bhi locha hai thik se dekho
#include <iostream>
using namespace std;
class animal
{
public:
    virtual void speak()
    {
        cout << "Speaking" << endl;
    }
    void show()
    {
        cout << "In Parent class" << endl;
    }
};
class dog : public animal
{
    public:
    void speak()
    {
        cout << "Barking " << endl;
    }
    virtual void show()
    {
        cout << "In Child class" << endl;
    }
};
int main()
{
    dog d;
    d.speak();
    d.show();
    cout << endl;
    animal *ani;
    dog d2;
    ani = &d2;
    ani->speak();
    ani->show();
    cout << endl;
    cout << &d2 << endl;
}