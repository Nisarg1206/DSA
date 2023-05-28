#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int n)
    {
        this->data = n;
        left = right = NULL;
    }
};

void preorder(node *p)
{
    if(p==NULL)
        return;

    cout << p->data << " ";

    preorder(p->left);

    preorder(p->right);
}

void postorder(node *p)
{
    if(p==NULL)
        return;

    postorder(p->left);

    postorder(p->right);
    
    cout << p->data << " ";
}

void inorder(node *p)
{
    if(p==NULL)
        return;

    inorder(p->left);
    
    cout << p->data << " ";
    
    inorder(p->right);  
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

    cout << "Pre-order Traversal is " << endl;
    preorder(root);

    cout << endl << endl;
    cout << "Post-order Traversal is " << endl;
    postorder(root);

    cout << endl << endl;
    cout << "In-order Traversal is " << endl;
    inorder(root);
}