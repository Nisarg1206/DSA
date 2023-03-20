#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double pow(double x,int n)
    {
        if(n==0)
        {
            return 1;
        }
        else
        {
            return x*pow(x,n-1);
        }
    }
    double myPow(double x, int n) {
        double t;
        double p;
        if(n<0)
        {
            p=pow(x,n*(-1));
            t=(double)(1/p);
        }
        else
        {
            t=pow(x,n);
        }
        return t;
    }
};

int main()
{
    double x;
    cin >> x;
    int n;
    cin >> n;
    Solution s;
    cout << s.myPow(x, n);
}

// class Solution {
// public:
//     double pow(double x,int n)
//     {
//         double ans;
//         if(n==0)
//         {
//             ans=1;
//             return ans;
//         }
//         else
//         {
//             if(n%2==0)
//             {
//                 ans=pow(x,n/2);
//                 return ans*ans;
//             }
//             else
//             {
//                 ans=pow(x,(n-1)/2);
//                 return ans*ans*x;
//             }
//         }
//     }
//     double myPow(double x, int n) {
//         double t;
//         if(x==1)
//         {
//             return x;
//         }
//         else
//         {
//         if(n<0)
//         {
//             long long p = abs((long long) n);
//             if(p%2==0)
//             {
//                 ans=pow(x,p/2);
//                 ans=1/(ans*ans);
//             }
//             return 1/pow(x,p);
//         }
//         else
//         {
//             t=(double)pow(x,n);
//             return t;
//         }
        
//     }}
// };