#include<bits/stdc++.h>
using namespace std;


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        vector<long long int> ans;
        queue<long long int>q;
        long long int i=0,j=0;
        while(j<N)
        {
            if(A[j]<0)
            {
                q.push(A[j]);
            }
            
            if(j-i+1<K)
            {
                j++;
            }
            else
            {
                    if(!q.empty())
                    {
                        ans.push_back(q.front());
                        if(q.front()==A[i])
                        {
                            q.pop();
                        }
                    }
                    else
                    {
                        ans.push_back(0);
                    }
                i++;
                j++;
            }
        }
        return ans;
        
 }
int main()
{
    long long int ans[]={12,-1, -7, 8, -15, 30, 16, 28};
    long long int k = 3, n = 8;

    vector<long long int> ans1 = printFirstNegativeInteger(ans,8,3);

    for (int i = 0; i < ans1.size();i++)
            cout << ans1[i] << " ";
}