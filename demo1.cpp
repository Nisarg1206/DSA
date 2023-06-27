#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &arr, int s, int e)
    {
        int mid = (s + e) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        // copy values
        int mainArrayIndex = s;
        for (int i = 0; i < len1; i++)
        {
            first[i] = arr[mainArrayIndex++];
        }

        mainArrayIndex = mid + 1;
        for (int i = 0; i < len2; i++)
        {
            second[i] = arr[mainArrayIndex++];
        }

        // merge 2 sorted arrays
        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;

        while (index1 < len1 && index2 < len2)
        {
            if (first[index1] < second[index2])
            {
                arr[mainArrayIndex++] = first[index1++];
            }
            else
            {
                arr[mainArrayIndex++] = second[index2++];
            }
        }

        while (index1 < len1)
        {
            arr[mainArrayIndex++] = first[index1++];
        }

        while (index2 < len2)
        {
            arr[mainArrayIndex++] = second[index2++];
        }

        delete[] first;
        delete[] second;
    }

    void mergeSort(vector<int> &arr, int s, int e, int &ans)
    {

        // base case
        if (s >= e)
        {
            return;
        }

        int mid = (s + e) / 2;

        // left part sort karna h
        mergeSort(arr, s, mid, ans);

        // right part sort karna h
        mergeSort(arr, mid + 1, e, ans);

        int right = mid + 1;
        for (int left = s; left <= mid;left++)
        {
            while(right<=e and (arr[left] > (long long)2 * arr[right]))
                right++;
            
                ans += right - mid - 1;
            
        }
        // merge
        merge(arr, s, e);
    }
    int reversePairs(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        mergeSort(nums, 0, n - 1, ans);
        return ans;
    }
};

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        unordered_map<long, int> m;
        int n = nums.size(), ans = 0;
        reverse(nums.begin(), nums.end());
        m[nums[0]]++;
        for (int i = 1; i < n; i++)
        {
            long j = nums[i];
            for (auto k : m)
            {
                if (j > 2 * k.first)
                    ans += k.second;
            }
            // if(m.find(if()))
            m[nums[i]]++;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};
    Solution s;
    int k = s.reversePairs(nums);
    cout << k << endl;
    // int n = nums.size();
    // for(auto i:nums)
    //     cout << i << " ";
}