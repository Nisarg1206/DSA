#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int compareValues(vector<int> potions, int s, int success)
    {
        float t = (float)success / s;
        int l = 0, h = potions.size() - 1;
        int count = 0;
        if (potions[h] < t)
        {
            return count;
        }
        else
        {
            while (l <= h)
            {
                int mid = (l + h) / 2;
                if (success== potions[mid])
                    return mid;
                else if (success < potions[mid])
                {
                    h = mid - 1;
                    return h;
                }
                else
                {
                    l = mid + 1;
                    return l;
                }
            }
        }
        return count;
    }

public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> answer;
        vector<float> spells2;
        sort(potions.begin(), potions.end());
        int i = 0, j = 0;
        while (i < spells.size())
        {
            int p = compareValues(potions, spells[i], success);
            answer.push_back(p);
            i++;
        }
        return answer;
    }
};

int main()
{
    int t = 1;
    vector<int> nums = {5, 1, 3}, k, p = {1, 2, 3, 4, 5};
    long long success = 7;
    Solution s;
    k = s.successfulPairs(nums, p, success);
    for (int i = 0; i < k.size(); i++)
    {
        cout << k[i] << " ";
    }
}