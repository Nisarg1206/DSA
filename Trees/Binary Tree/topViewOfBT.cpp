#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *BuildTree(node *root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting at left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data for inserting at right of " << data << endl;
    root->right = BuildTree(root->right);
}

// 1st solution but way more space
//  vector<int> topOrder(node *root)
//  {
//      map<int, map<int, unordered_set<int>>> m;
//      queue<pair<node *, pair<int, int>>> q;
//      q.push({root, {0, 0}});
//      while (!q.empty())
//      {
//          auto p = q.front();
//          q.pop();
//          int x = p.second.first, y = p.second.second;
//          m[x][y].insert(p.first->data);
//          if (p.first->left != NULL)
//          {
//              q.push({p.first->left, {x - 1, y + 1}});
//          }
//          if (p.first->right != NULL)
//          {
//              q.push({p.first->right, {x + 1, y + 1}});
//          }
//      }

//     vector<int> ans;
//     for (auto i : m)
//     {
//         vector<int> temp;
//         for (auto t : i.second)
//         {
//             temp.insert(temp.end(), t.second.begin(), t.second.end());
//         }
//         ans.push_back(temp[0]);
//     }
//     return ans;
// }

vector<int> topOrder(node *root)
{
    map<int, int> m;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto i = q.front();
        q.pop();
        int x = i.second;
        if (m.find(i.second) == m.end())
        {
            m[x] = i.first->data;
        }

        if (i.first->left != NULL)
        {
            q.push({i.first->left, x - 1});
        }
        if (i.first->right != NULL)
        {
            q.push({i.first->right, x + 1});
        }
    }
    vector<int> ans;
    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    node *root;
    root = BuildTree(root);
    vector<int> v = topOrder(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

// 1 2 3 -1 -1 7 11 -1 -1 -1 4 5 -1 -1 10 -1 -1

