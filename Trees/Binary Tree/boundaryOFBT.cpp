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

void leftSide(node *root, vector<int> &ans)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            ans.push_back(root->data);
            leftSide(root->left, ans);
        }
        else if (root->right != NULL)
        {
            ans.push_back(root->data);
            leftSide(root->right, ans);
        }
    }
    else
        return;
}

void rightSide(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    else
    {
        if (root->right != NULL)
        {
            rightSide(root->right, ans);
            ans.push_back(root->data);
        }
        else if (root->left != NULL)
        {
            rightSide(root->left, ans);
            ans.push_back(root->data);
        }
    }
}
void leavies(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    else
    {
        leavies(root->left, ans);

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }

        leavies(root->right, ans);
    }
}
int count(node *root, vector<int> &ans)
{
    if (root != NULL)
    {
        count(root->left, ans);
        count(root->right, ans);
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
    }
}
vector<int> boundaryBT(node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    leftSide(root->left, ans);

    leavies(root->left, ans);
    leavies(root->right, ans);

    rightSide(root->right, ans);

    return ans;
}

int main()
{
    node *root = NULL;
    root = BuildTree(root);

    vector<int> ans = boundaryBT(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

// 1 2 3 -1 4 5 -1 -1 6 -1 -1 -1 7 -1 8 10 -1 -1 11 -1 -1 -1
// 1 -1 2 -1 3 -1 4 -1 7 -1 10 -1 99 -1 -1
// 1 2 3 50 85 12 32 N 85 N N N N N N N N

