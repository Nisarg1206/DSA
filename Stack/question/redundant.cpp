#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter string " << endl;
    cin >> str;
    stack<char> s;
    int state = 0,k=0;
    for (int i = 0; i < str[i] != '\0';i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else if(str[i]=='*' || str[i]=='/' || str[i]=='+' || str[i]=='-')
        {
            k++;
        }
        else if( str[i]==')' || str[i]=='}' || str[i]==']')
        {
            k--;
            s.pop();
        }
    }
    if(k<0)
    {
        cout << "Redundant brackets is present" << endl;
    }
    else
    {
        cout << "Redundant brackets is not present" << endl;
    }
}