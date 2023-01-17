#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int age;
    bool gender; // 1 for male 0 for female
    void printDetail()
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "gender = " << gender << endl;
    }
    student (string s,int a,int g)
    {
        name = s;
        age = a;
        gender = g;
    }//paramterised constuctor
    student()
    {
        cout << "Default Constuctor" << endl;
    }
    student (student &a)
    {
        name = a.name;
        age = a.age;
        gender = a.gender;
    }//Copy Constuctor
    ~student ()
    {
        cout << "Destructor called" << endl;
    }//destructor 
    bool operator ==(student &a)
    {
        if(name ==a.name&&age == a.age && gender== a.gender)
            return true;
        return false;
    }
};
int main(){
    int n;
    cin >> n;
    student a[n];
    for (int i = 0; i < n;i++)
    {
        cout << "Name = ";
        cin >> a[i].name;
        cout << "Age = ";
        cin >> a[i].age;
        cout << "Gender = ";
        cin >> a[i].gender;
    }
    for (int i = 0; i < n;i++)
    {
        a[i].printDetail();
    }
    student c=a[0];
    if(c == a[0])
    {
        cout << "Same" << endl;
    }
    else
        cout << "Not same" << endl;
}