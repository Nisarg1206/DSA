#include <bits/stdc++.h>
using namespace std;

int indexBinary(int a[], int first, int last, int target)
{
    int mid = (first + last) / 2;
    while (first <= last)
    {
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
        {
            first = mid + 1;
            return indexBinary(a, first, last, target);
        }
        else
        {
            last = mid - 1;
            return indexBinary(a, first, last, target);
        }
    }
    
        return mid +1;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0;
    int k;
    cin >> k;
    int p = indexBinary(a, 0, n-1, k);
    cout << endl
         << endl
         << p;
}