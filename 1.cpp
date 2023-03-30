#include<bits/stdc++.h>
using namespace std;

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    char c = 97+5;
    cout << c << endl;
    map<char, int> m;
    for (int i = 0; i < key.length();i++)
    {
        if(key[i]!=' ')
        {
            m[key[i]] = 97+i;
        }
    }
    vector<char> str;
    for (int i = 0; i < message.length();i++)
    {
        if(message[i]==' ')
        {
            char c = ' ';
            str.push_back(c);
        }
        else
        {
            char c = m[message[i]];
            str.push_back(c);
        }
    }
    cout << endl;
    // cout << str << endl;
    for(auto i: str)
    {
        cout << str[i] << " ";
    }
}