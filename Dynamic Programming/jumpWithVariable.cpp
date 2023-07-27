#include <bits/stdc++.h>
using namespace std;

int climbStair(vector<int> costs)
{
    int n = costs.size();
    vector<int> steps(n + 1,0);
    steps[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= costs[i] && i + j < steps.size(); j++)
        {
            steps[i] += steps[i + j];
        }
    }
    return steps[0];
}

int main()
{
    vector<int> costs = {2, 3, 0, 1, 2, 3};
    cout << climbStair(costs);
}