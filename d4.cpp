#include <bits/stdc++.h>
#include <set>
using namespace std;

int main()
{
    multiset<int> s;
    s.insert(52);
    s.insert(84);
    s.insert(84);
    vector<int> temp;
    s.erase(84);
    auto search = s.find(84);
    if (search != s.end())
    {
        cout << " found and the value is " << *search << '\n';
    }
    else
    {
        cout << " not found\n";
    }
}

class RandomizedCollection
{
public:
    vector<int> temp;
    unordered_map<int, int> s;
    RandomizedCollection()
    {
        // no code
    }

    bool insert(int val)
    {
        if (s[val] == 0)
        {
            temp.push_back(val);
            s[val]++;
            return true;
        }
        else if (s[val] > 0)
        {
            temp.push_back(val);
            s[val]++;
            return false;
        }
        return false;
    }

    bool remove(int val)
    {
        if (s[val] > 0)
        {
            auto it = find(temp.begin(), temp.end(), val);
            temp.erase(it);
            s[val]--;
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return temp[rand() % temp.size()];
    }
};
