#include <iostream>
using namespace std;
#include<string.h>
class hero
{

public:
    int health;
    char level;
    char *name;
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
    string setterName(char name[100])
    {
        strcpy(this->name, name);
    }
    string getterName()
    {
        return name;
    }
    //Default Constuctor
    hero()  
    {
        cout << "Default Constuctor Called" << endl;
        name = new char[100];
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
        // cout << "Copy Constructor called" << endl;
        char *ch = new char[strlen(t.name) + 1];
        strcpy(ch,t.name);
        this->name = ch;
        this->health = t.health;
        this->level = t.level ;
    }
    void print()
    {
        cout << endl;
        cout << "Name is " << getterName() << endl;
        cout << "Health is " << getterHealth() << endl;
        cout << "Level is " << getterLevel() << endl;
        cout << endl;
    }
};
int main()
{
    hero hero1;
    hero1.setterHealth(12);
    hero1.setterLevel('F');
    char name[] = "Nisarg";
    hero1.setterName(name);

    hero hero2(hero1);

    hero1.print();

    hero2.print();

    name[0] = 'K';
    hero1.setterName(name);
    hero1.print();

    hero2.print();
}