//Remove Element

#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &nums,int val)
{
    int n = nums.size();
    for (int i = 0; i < n;i++)
    {
        if(nums[i]==val)
        {
            nums.erase(nums.begin() + i);
        }
    }
}

int main()
{
    int t = 1;
    vector<int> nums;
    while(t)
    {
        int p;
        cin >> p;
        nums.push_back(p);
    }
    int val;
    cin >> val;
    int p=removeElement(nums,val);
}