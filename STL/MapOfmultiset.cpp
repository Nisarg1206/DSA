#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, multiset<int>> m;

    m[1].insert(12);
    m[2].insert(15);

    for(auto i:m)
    {
        for(auto p:i.second)
        cout << i.first << " " <<p.first()  << endl;
    }
}