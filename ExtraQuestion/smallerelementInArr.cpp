#include<bits/stdc++.h>
using namespace std;

vector<int> smallerElement(vector<int> nums)
{
    vector<int>answer;
    stack<int> st;
    for (int i = nums.size()-1; i >=0 ;i--)
    {
        st.push(nums[i]);
    }
    int i = 0;
    while(!st.empty())
    {
        int p = 0;
        stack<int> s1=st;
        do
        {
            if(s1.top()<nums[i])
            {
                p++;
            }
            s1.pop();
        } while (!s1.empty());
        answer.push_back(p);
        st.pop();
        i++;
    }
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