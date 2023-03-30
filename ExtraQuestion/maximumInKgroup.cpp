#include <bits/stdc++.h>
using namespace std;
int maximum(vector<int> nums)
{
    int max = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }
    }
    return max;
}

vector<int> slidingWindow(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> result;
    vector<int> max3;
    int i = 0;
    int h = 0;
    while (i < n)
    {
        if (h < k && i < n)
        {
            max3.push_back(nums[i]);
            h++;
        }
        else
        {
            h = 0;
            int p = maximum(max3);
            max3.clear();
            result.push_back(p);
        }
        i++;
    }
    return result;
}
int main()
{
    int t = 1;
    vector<int> nums;
    while (t)
    {
        int p;
        cin >> p;
        nums.push_back(p);
        cout << "Yes/No" << endl;
        cin >> t;
    }
    int k;
    cin >> k;
    nums = slidingWindow(nums, k);
    for (auto i : nums)
    {
        cout << nums[i] << " ";
    }
}
