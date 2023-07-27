#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n,vector<int>&dp)
    {
        if(n<=0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }

        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }
public:
    int fibonacci(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

int main()
{
    int n = 10;
    Solution s;
    cout << s.fibonacci(n);
}