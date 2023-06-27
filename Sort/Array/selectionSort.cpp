#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&nums)
{
    int n = nums.size(),k , j;

    for (int i = 0; i < n;i++)
    {

        for (j = k = i; j < n ;j++)
        {
            if(nums[j]<nums[k])
            {
                k = j;
            }
        }
        int p = nums[k];
        nums[k] = nums[i];
        nums[i] = p;
    }
}
int main()
{
    vector<int> nums;

    nums = {8, -1,2,7,-9,32,0,1};

    selectionSort(nums);

    int n = nums.size();

    for (int i = 0; i < n;i++)
    {
        cout << nums[i] << " ";
    }
}