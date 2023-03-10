#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void insertAtBottom(stack<int> &input,int bottom)
    {
        int n=input.size();
        int a[n];
        for (int i = 0; i < n;i++)
        {
            a[n] = input.top();
            input.pop();
        }
        input.push(bottom);
        for (int i = 0; i < n;i++)
        {
            input.push(a[i]);
        }
    }
};

int main()
{
    stack<int> st;
    st.push(5);
    st.push(12);
    st.push(10);
    st.push(89);
    st.push(84);

}