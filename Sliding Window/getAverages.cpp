//question- https://leetcode.com/problems/k-radius-subarray-averages/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        vector<int> ans;
        int n = nums.size();
        long sum = 0;
        if (k <= n)
        {
            int i = 0, j = 0;
            while (j < n)
            {
                sum += nums[j];
                if (j - i + 1 < 2 * k + 1)
                {
                    j++;
                    if(j-i+1<k)
                    ans.push_back(-1);
                }
                else
                {
                    long temp = sum / ((2 * k) + 1);
                    ans.push_back(temp);
                    i++;
                    j++;
                    sum = sum - nums[i - 1];
                }
            }

            int t = ans.size();
            while(t<n)
            {
                ans.push_back(-1);
                t++;
            }
        }
        else
        {
            while (n--)
                ans.push_back(-1);
            return ans;
        }
    }
};

int main()
{
    vector<int> v(6, -1);
    // v.insert(0, -1);
    int i = 0;
    while(i<3)
    {
        replace(v.begin() + i, v.end(), -1, 9);
    }

    for (int p = 0; p < v.size();p++)
    {
        cout << v[i] << " ";
    }
}