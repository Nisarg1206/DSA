#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[2 * n], b[2 * n];
        for (int i = 0; i < 2 * n;i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < (2 * n);i++)
        {
            b[i] = a[i];
        }
        int p, q;
        sort(b, b + (2 * n));
        p = b[n - 1];
        q=n;
        long ans = 0;
        for (int i = 0; i < q;i++)
        {
            if(a[i]>p)
            {
                ans = ans + q - i;
                q++;
            }
        }
    }
}