#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;

    node(int p)
    {
        this->data = p;
        left = right = NULL;
    }
};

int count(node *p)
{
    int x = 0, y = 0;
    if(p!=NULL)
    {
        x = count(p->left);
        y = count(p->right);
        if(p->left!=NULL || p->right!=NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right->left = new node(7);
    root->right->right = new node(8);
    root->right->right->left=new node(9);
    root->right->right->right = new node(10);

    int p = count(root);
    cout << "No of Nodes in Binary tree is " << p << endl;
}



/* degree 0 
condition is 
if(p->left==NULL && p->right==NULL)

degree 2
condition is 
if(p->left!=NULL && p->right!=NULL)

degree 1 
if(p->left!=NULL ^ p->right!=NULL)

degree 2 or 1
condition is 
if(p->left!=NULL || p->right!=NULL)


all degree for
no condition
*/