#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int x)
    {
        this->data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    node *kthSmallest(node *root, int &k) 
    {
        if(root==NULL)
        {
            return;
        }

        node *left = kthSmallest(root->left, k);

        if(left!=NULL)
        {
            return left;
        }

        if(k==1)
        {
            return root;
        }
        else{
            k--;
        }

        return kthSmallest(root, k);
    }
    public : int kthSmall(node *root, int k)
    {
        return kthSmallest(root, k)->data;
    }
}