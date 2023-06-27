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


vector<vector<int>> verticalOrder(node *root)
{
    map<int, map<int, multiset<int>>> m;
    queue<pair<node *, pair<int, int>>> q;
    q.push({root,{0,0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.second.first,y=p.second.second;
        m[x][y].insert(p.first->data);
        if(p.first->left!=NULL)
        {
            q.push({p.first->left, {x - 1, y + 1}});
        }
        if(p.first->right!=NULL)
        {
            q.push({p.first->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for(auto i:m)
    {
        vector<int> temp;
        for(auto t:i.second)
        {
            temp.insert(temp.end(), t.second.begin(), t.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    node *root;
    root = BuildTree(root);

    vector<vector<int>> v = verticalOrder(root);

    for (int i = 0; i < v.size();i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

//1 2 4 -1 5 -1 6 -1 -1 10 -1 -1 3 9 -1 -1 10 -1 -1