#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void insertAtBottom(stack<int> &input,int bottom)
    {
        if(input.empty())
        {
            input.push(bottom);
            return;
        }
        int p = input.top();
        input.pop();

        insertAtBottom(input, bottom);

        input.push(p);
    }
    
    void reverseRecursion(stack<int>&input)
    {
        if(input.empty())
        {
            return;
        }
        int p = input.top();
        input.pop();

        reverseRecursion(input);

        insertAtBottom(input, p);
    }

    
    
};


int main()
{
    stack<int> st;
    st.push(6);
    st.push(12);
    st.push(10);
    st.push(89);
    st.push(84);

    
    Solution s;
    cout << "New stack is" << endl;
    s.reverseRecursion(st);
    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}