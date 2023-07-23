#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
    node(int x)
    {
        this->data=x;
        left = NULL;
        right = NULL;
    }
};

node* insertNode(node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }

    node *cur = root;

    while(cur!=NULL)
    {
        if(cur->data<=key)
        {
            if(cur->right!=NULL)
            {
                cur = cur->right;
            }
            else
            {
                cur->right = new node(key);
                break;
            }
        }
        else{
            if(cur->left!=NULL)
            {
                cur = cur->left;
            }
            else
            {
                cur->left = new node(key);
                break;
            }
        }
    }
    return root;
}