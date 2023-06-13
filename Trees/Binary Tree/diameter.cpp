#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int p)
    {
        this->data = p;
        left = right = NULL;
    }
};

class demo
{
public:
    int diameter(node *root)
    {
        int ans = diam(root);
        return ans;
    }

private:
    int height(node *p)
    {
        int x = 0, y = 0;
        if (p != NULL)
        {
            x = height(p->left);
            y = height(p->right);

            return 1 + max(x, y);
        }
        return 0;
    }
    int diam(node *p)
    {
        int x = 0, y = 0;
        if (p != NULL)
        {
            x = diam(p->left);
            y = diam(p->right);

            int d = height(p->left) + height(p->right)+1;

            return max(d, max(x, y));
        }
        return 0;
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
int main()
{
    
    node *root = NULL;
    root = BuildTree(root);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->left->right->left = new node(6);
    // root->right->left = new node(7);
    // root->right->right = new node(8);
    // root->right->right->left = new node(9);
    // root->right->right->right = new node(10);
    // root->right->right->right->left = new node(11);
    // root->right->right->right->left->left = new node(12);
    // root->right->left->left = new node(13);
    // root->right->left->left->left = new node(14);
    // root->right->left->left->left->left = new node(15);
    // root->right->left->left->left->left->left = new node(16);
    // root->right->left->left->left->left->left->left = new node(17);
    // root->right->right->right->left->left->left = new node(18);

    demo s;
    cout << "No of Nodes in Binary tree is " << s.diameter(root) << endl;
}