#include<iostream>
using namespace std;
class students{
    //Encapsulation
    private:
        string name;
        int rollNo;
        int age;

    public:
    int getRollNo()
    {
        return rollNo;
    }

    //constructor bhai
    students() 
    {
        cout << "Default constructor bhai" << endl;
        this->name = "Nisarg";
        this->rollNo = 2106191;
        this->age = 19;
    }
};
int main()
{
    students Nisarg;
    cout << "Student Roll No. is " << Nisarg.getRollNo()<<endl;
}