#include <iostream>
using namespace std;
class NITPStudent
{
public:
    string name;
    int height;
    int age;
    string branch;
};
class CSEstudent
{
public:
    int rollNo;
    int noOfSubject;
};
class student : public CSEstudent, public NITPStudent  //Using Multiple Inheritance 
{
public:
    int CGPA;
};
int main()
{
    student s1;
    s1.name = "Nisarg";
    s1.age = 19;
    s1.height = 178;
    s1.branch = "Computer science engineering";
    s1.rollNo = 2106191;
    s1.noOfSubject = 6;
    s1.CGPA = 9;
    cout << "Name : " << s1.name << endl;
    cout<<"Age is : "<<s1.age<<endl;
    cout << "Height is  : " << s1.height << endl;
    cout << "Branch is : " << s1.branch << endl;
    cout << "rollNo is :" << s1.rollNo << endl;
    cout << "No of subject is : " << s1.noOfSubject << endl;
    cout << "CGPA is : " << s1.CGPA << endl;
}
