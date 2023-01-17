#include <iostream>
using namespace std;
class hero
{

public:
    int health;
    char level;
    string name;
    static int timeToComplete;
    int setterHealth(int h)
    {
        health = h;
    }
    int getterHealth()
    {
        return health;
    }
    char setterLevel(char ch)
    {
        level = ch;
    }
    char getterLevel()
    {
        return level;
    }
    string setterName(string str)
    {
        name = str;
    }
    string getterName()
    {
        return name;
    }

    //Default Constuctor
    hero()  
    {
        cout << "Default Constuctor Called" << endl;
    }

    //Parameterised Constructor
    hero(int health,char ch) 
    {
        this->health = health;
        this->level = ch;
        // cout << "Address of heroCall by this keyword is " << this<<endl;
        cout << "Parameterised Constructor Called" << endl;
    }

    //Copy Constuctor
    hero(hero &t)
    {
        cout << "Copy Constructor called" << endl;
        this->health = t.health*2;
        this->level = t.level + 2;
    }
    void print()
    {
        cout << "Health is " << getterHealth() << endl;
        cout << "Level is " << getterLevel() << endl;
    }
    ~hero()
    {
        cout << "Default Destructor Called" << endl;
    }
    static int demo()
    {
        timeToComplete = 15;
        return timeToComplete;
    }
};
int hero::timeToComplete = 100;
int main()
{
    cout << hero::timeToComplete << endl;
    hero::timeToComplete = 20; 
    cout << hero::demo() << endl;
    hero a;
    cout << a.demo() << endl;
    // hero heroCall(21,'d');
    // heroCall.setterLevel('b');
    // cout << "Level of hero is " << heroCall.getterLevel() << endl;
    // cout << "Enter Name is" << endl;
    // string name;
    // cin >> name;
    // heroCall.setterName(name);
    // cout << "Name of hero is " << heroCall.getterName() << endl;
    // cout << "Health is " << heroCall.getterHealth() << endl;
    // cout << "Address of heroCall by pointer is " << &heroCall<<endl;
    // hero ramesh;          //by default constructor deleted by compiler when we created parametrized constructor if alerady created default constructor
    // cout << "Health is " << ramesh.getterHealth();
}

// :: is called as scope resolution operator
