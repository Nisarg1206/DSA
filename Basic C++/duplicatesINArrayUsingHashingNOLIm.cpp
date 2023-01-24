#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k;
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    if (min < 0)
    {
        k = max + 2 + (-1) * min;
    }
    else
    {
        k = max + 2;
    }
    int h[k];
    for (int i = 0; i < k; i++)
    {
        h[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= max && a[i] >= 0)
        {
            h[a[i]]++;
        }
        else
        {
            h[a[i] * (-1) + max]++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (i <= max)
        {
            if (h[i] > 1)
            {
                cout << i << " is " << h[i] << " times present in array" << endl;
            }
        }
        else
        {
            if (h[i] > 1)
            {
                cout << max - i << " is " << h[i] << " times present in array" << endl;
            }
        }
    }
    int z=h[0],j;
    for (int i = 0; i < k;i++)
    {
        if(h[i]>z)
        {
            z=h[i];
            if(i<=max)
            {
                j = i;
            }
            else
            {
                j = max - i;
            }
        }
    }
    cout << "most repeating element is " << j << endl;
}