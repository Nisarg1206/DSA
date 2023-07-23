// Q. https://leetcode.com/problems/binary-tree-paths/description/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};
class Solution
{
    void btPath(node *root, vector<string> &ans, string str) // I couldn't take address of string becuase if we take so manually delete current element when we back to parent node
    {
        if (root == NULL)
            return;

        str += to_string(root->data) + "->";

        if (root->left == NULL && root->right == NULL)
        {
            str.erase(str.length() - 2, str.length());
            ans.push_back(str);
        }

        btPath(root->left, ans, str);

        btPath(root->right, ans, str);
    }

public:
    vector<string> binaryTreePaths(node *root)
    {
        vector<string> ans;
        if (root == NULL)
            return ans;

        string str = "";
        btPath(root, ans, str);
        return ans;
    }
};

