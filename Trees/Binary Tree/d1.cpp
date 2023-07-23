#include <bits/stdc++.h>
using namespace std;

int sol(int l, int r, int arr[500][500], string s)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (arr[l][r] != -1)
        return arr[l][r];

    int res = 1 + sol(l + 1, r, arr, s);
    for (int i = l + 1; i <= r; ++i)
    {
        if (s[l] == s[i])
            res = min(res, sol(l + 1, i - 1, arr, s) + sol(i, r, arr, s));
            // if(res>(sol(l + 1, i - 1, arr, s) + sol(i, r, arr, s)))
            // {
            //     res = sol(l + 1, i - 1, arr, s) + sol(i, r, arr, s);
            // }
    }
    return arr[l][r] = res;
}

int getMinOperation(string s)
{
    int n = s.length();
    int dp[500][500];
    memset(dp, -1, sizeof dp);
    return sol(0, n - 1, dp, s);
}
int main()
{
    string s = "aabvibaia";
    cout<<getMinOperation(s);
}