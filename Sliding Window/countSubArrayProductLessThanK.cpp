//Question. https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1

#include <bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    long long pr = 1;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        pr *= a[i];

        while (j < i and pr >= k)
        {
            pr /= a[j];
            j++;
        }

        if (pr < k)
        {
            ans += (i - j + 1);
        }
    }
    return ans;
}