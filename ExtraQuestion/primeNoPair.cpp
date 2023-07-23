#include<bits/stdc++.h>
using namespace std;

class Solution
{
    bool primeNo(int n)
    {
        if (n <= 1)
            return 0;
        if (n == 2 || n == 3)
            return 1;
        if (n % 2 == 0 || n % 3 == 0)
            return 0;
        for (int i = 5; i * i <= n; i = i + 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return 0;
        }
        return 1;
    }

public:
    vector<vector<int>> findPrimePairs(int n)
    {
        vector<vector<int>> ans;
        for(int i=2;i<=(n/2);i++)
        {
            bool p=primeNo(n-i),d=primeNo(i);
            if(p and d)
            {
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};

int main()
{
    int n = 853329;

    Solution s;

    vector<vector<int>> ans = s.findPrimePairs(n);

    for (int i = 0; i < ans.size();i++)
    {
        for (int j = 0; j < ans[i].size();j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}