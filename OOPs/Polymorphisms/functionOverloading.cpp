/*
Function overloading is achieved by when class contain 
same name but different arguments or different type of return type
*/

#include<iostream>
using namespace std;
class human{
    public:
        void speak()
        {
            cout << "Human speak"<<endl;
        }
        void speak(int n)
        {
            cout << "Human speaking " <<n*n<< endl;
        }
        human()
        {
            cout << "Constructor called" << endl;
        }
        ~human()
        {
            cout << "Destructor called" << endl;
        }
};
int main()
{
        human h1;
        h1.speak();
        h1.speak(10);
}