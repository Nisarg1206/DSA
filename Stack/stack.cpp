#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Creation of stack
    stack<int> s;

    //Push element
    s.push(25);
    s.push(84);
    s.push(12);

    //Pop element
    s.pop();

    //Top element
    cout << "Top element is " << s.top() << endl;

    //Size of stack
    cout << "Size of stack is " << s.size() << endl;
}