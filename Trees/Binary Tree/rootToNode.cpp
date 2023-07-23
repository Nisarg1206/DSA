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

class Solution
{
    bool rootNode(node* root,vector<int>&ans,int x)
    {
        if(root==NULL)
            return false;

        ans.push_back(root->data);

        if(root->data==x)
            return true;

        if(rootNode(root->left,ans,x) || rootNode(root->right,ans,x))
            return true;

        ans.pop_back();
        return false;
    }
public:
    vector<int> rootToNode(node *root,int x)
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }

        rootNode(root, ans,x);
        return ans;
    }
};
int main()
{
    node *root;
    root = BuildTree(root);

    Solution s;
    vector<int> ans = s.rootToNode(root, 7);

    for (int i = 0; i < ans.size();i++)
    {
        cout << ans[i] << " ";

    }
}