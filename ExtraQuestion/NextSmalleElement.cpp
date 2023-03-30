#include<bits/stdc++.h>
using namespace std;

vector<int> smallerElement(vector<int> nums)
{
    vector<int>answer;
    stack<int> st;
    st.push(-1);
    for (int i = nums.size() - 1; i >=0;i--)
    {
        int curr = nums[i];
        while(st.top()>curr)
        {
            st.pop();
        }
        answer.push_back(st.top());
        st.push(curr);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main()
{
    int t = 1;
    vector<int> nums,k;
    while(t)
    {
        int p;
        cin >> p;
        nums.push_back(p);
        cout << "Yes/No" << endl;
        cin >> t;
    }
    k=smallerElement(nums);
    for (int i = 0; i < k.size();i++)
    {
        cout << k[i] << " ";
    }
}