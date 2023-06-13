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

int main()
{
    node *root = NULL;
    root = BuildTree(root);

    // vector<vector<int>>ans= LevelOrder(root);
    // for(int i=0;i<ans.size();i++)
    // {
    //     for(int j=0;j<ans[i].size();j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout << endl;
    // ReverseLevelOrder(root);
}