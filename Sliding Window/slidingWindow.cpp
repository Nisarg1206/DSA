//question -https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        long maxi=0,sum=0;
        int i=0,j=0;
        while(j<N)
        {
            sum+=arr[j];
            if(j-i+1<K)
            {
                j++;
            }
            else
            {
                if(maxi<sum)
                {
                    maxi=sum;
                }
                i++;
                j++;
                sum=sum-arr[i-1];
            }
        }
        return maxi;
    }
};