#include<bits/stdc++.h>
using namespace std;
int mergeSort(vector<int>&nums,int first,int last)
{
    int mid = (first + last) / 2;
    //LeftSide
    mergeSort(nums, first, mid);
    //RightSide
    mergeSort(nums, mid + 1, last);

    int len1 = mid - first + 1;
    int len2 = mid - last;
    vector<int> leftPart,rightPart;
    int j = first;
    for (int i = 0; i < len1;i++)
    {
        int p = nums[j];
        j++;
        leftPart.push_back(p);
    }
    for (int i = 0; i < len2;i++)
    {
        int p = nums[j];
        j++;
        rightPart.push_back(p);
    }
    int i1=0, i2=0;
    j = first;
    while(i1<len1 && i2<len2)
    {
        if(leftPart[i1]<rightPart[i2])
        {
            nums.insert(j, leftPart[i1]);
        }
    }
}
int mergeSorted(vector<int>&nums)
{
    mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    int t = 1;
    vector<int> nums;
    while(t)
    {
        int p;
        cin >> p;
        nums.push_back(p);
    }
    mergeSorted(nums);
    for(auto i:nums)
    {
        cout << nums[i] << " ";
    }
}