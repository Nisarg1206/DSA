#include <bits/stdc++.h>
using namespace std;

int minimumMoves(vector<int> jumps)
{
    int n = jumps.size();
    vector<int> dp(n + 1,INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0;i--)
    {
        if(jumps[i]>0)
        {
            int mini = INT_MAX;
            for (int j = 1; j <= jumps[i] && i + j < n + 1;j++)
            {
                if(dp[i+j]!=INT_MAX)
                {
                    mini = min(mini, dp[i + j]);
                }
            }
            if(mini!=INT_MAX)
            dp[i] = mini + 1;
        }
    }
    return dp[0];
}

int main()
{
    vector<int> costs = {1,1,1,4,9,8,1,1,10,1};
    cout << minimumMoves(costs);
}
