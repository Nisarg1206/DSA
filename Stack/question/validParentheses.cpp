#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validParenthese(string str)
    {

        stack<char> s;
        for (int i = 0; i < str.length(); i++)
        {

            char ch = str[i];

            // if opening bracket, stack push
            // if close bracket, stacktop check and pop

            if (ch == '(' || ch == '{' || ch == '[')
            {
                s.push(ch);
            }
            else
            {
                // for closing bracket
                if (!s.empty())
                {
                    char top = s.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '['))
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        if (s.empty())
            return true;
        else
        {
            return false;
        }
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    bool p=s.validParenthese(str);
    if(p)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}