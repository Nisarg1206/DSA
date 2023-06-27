#include <bits/stdc++.h>
using namespace std;


int main()
{
    map<int, int> m;
    m[1] = 3;
    m[1] = 8;

    multimap<int, int> m1;
    m1.insert({1, 100});
    m1.insert({-1, 10});
    cout << "For map" << endl;
    for(auto i:m)
        cout << i.first << " " << i.second << endl;

    cout << "For multimap" << endl;
    for(auto i:m1)
        cout << i.first << " " << i.second << endl;

}

// multimap store value in sorted way but if first value already exist in record than also multimap insert that value as new record but
// in map if value is exist in record than that value updated in records 
// both insert value in sorted way accprding to tha first datatype