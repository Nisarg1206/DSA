#include <bits/stdc++.h>
using namespace std;
// Sieve of Eratosthenes
int main()
{
    int t = 0, n;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p < n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}