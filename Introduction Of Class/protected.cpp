#include<iostream>
using namespace std;

class human
{
    protected:
    // private:
    string name;
    int age;
    int height;

    void setterAge(int b)
    {
        this->age = b;
    }
    int getterAge()
    {
        return this->age;
    }
    human()
    {
        cout << "Parent Constructor Called" << endl;
    }
};
class male :public human
{
    public:
    void setterAge(int a)
    {
        this->age = a;
    }
    int display()
    {
        return this->age;
    }
    male()
    {
        cout << "Child constructor called" << endl;
    }
};
int main()
{
    male m1;
    m1.setterAge(19);
    cout<<"My age is "<<m1.display();
}
