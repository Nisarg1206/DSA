#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-arithmetic-subsequence/description/
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 2)
            return n;

        int ans = 0;
        unordered_map<int, int> m[n + 1]; // Array of map  First int hoga woh index hoga and second one is difference 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                int c = 1;

                if (m[j].count(diff))
                    c = m[j][diff];

                m[i][diff] = 1 + c;
                ans = max(ans, m[i][diff]);
            }
        }
        return ans;
    }
};
int main()
{
    unordered_map<int, int> m[1];

    m[0][1] = 3;
}