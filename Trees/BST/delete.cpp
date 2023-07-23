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

class solution
{
    node *deleteNode(node *root)
    {
        if(root->left==NULL)
        {
            return root->right;
        }
        else if(root->right==NULL)
        {
            return root->left;
        }

        node *rightChild = root->right;
        node *lastRight = lastR(root->left);
        lastRight->right = rightChild;

        return root->left;
    }

    node* lastR(node*root)
    {
        if(root->right==NULL)
        {
            return root;
        }

        return lastR(root->right);
    }
public:
    node *deleteNode(node *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root->data == key)
        {
            return deleteNode(root);
        }

        node *cur = root;
        while(!cur)
        {
            if(cur->data>key)
            {
                if(cur->left!=NULL and cur->left->data==key)
                {
                    cur->left = deleteNode(cur->left);
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
            else
            {
                if(cur->right!=NULL and cur->right->data==key)
                {
                    cur->right = deleteNode(cur->right);
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};