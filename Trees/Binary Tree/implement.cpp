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

int main()
{
    struct node *root = new node(100);
    root->left = new node(20);
    root->right = new node(200);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->right->left = new node(150);
    root->right->right = new node(300);
}