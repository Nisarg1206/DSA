//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007  //Mod wale question mai sari jagah mod lagana hai

// } Driver Code Ends
class Solution{
    long long powerTo(int n,int r)
    {
        if(r==0)
        {
            return 1;
        }
            long long t=powerTo(n,r%2);
            
    }
    public:
    //You need to complete this fucntion
    
    long long power(int N,int r)
    {
       if(r==0)
       {
           return 1;
       }
       long long t=power(N,r/2);
       
       if(r%2==0)
       {
           t=(t*t)%mod;
       }
       else
       {
           t=(((t*t)%mod)*N)%mod;
       }
       
       return t%mod;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends