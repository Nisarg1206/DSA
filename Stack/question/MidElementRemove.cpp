#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int deleteMid(stack<int> &input, int n)
    {
        int count = (n + 1) / 2;
        solve(input, count, n);
    }
    int solve(stack<int> &input, int cnt, int n)
    {
        int arr[cnt];
        int i = 0;

        while (i < cnt)
        {
            int p = input.top();
            input.pop();
            arr[i] = p;
            i++;
        }
        input.pop();
        for (i = cnt - 1; i >= 0;i--)
        {
            int t = arr[i];
            input.push(t);
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

    Solution s;
    s.deleteMid(st, st.size() - 1);

    cout << st.size() << endl;
    while(!st.empty())
    {
        int p = st.top();
        cout << p << endl;
        st.pop();
    }
    
    return 0;
}

//stack ko empty properties se karana