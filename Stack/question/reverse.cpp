#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int i = 0,j=str.size()-1;
    while(i<=j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    cout << "Reverse String is" << endl;
    cout << str << endl;
    return 0;
}
void swap(char &s1,char &s2)
{
    char temp=s1;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

//Space complexity is order of 1 and time complexity is order of N