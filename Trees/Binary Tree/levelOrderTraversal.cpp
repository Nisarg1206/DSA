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

void levelOrder(node *p)
{
    queue<node*>q;
    cout << p->data << " ";
    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->left)
        {
            cout << p->left->data << " ";
            q.push(p->left);
        }
        if(p->right)
        {
            cout << p->right->data<< " ";
            q.push(p->right);
        }
    }
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

    cout << "Level-order Traversal is " << endl;
    levelOrder(root);
}