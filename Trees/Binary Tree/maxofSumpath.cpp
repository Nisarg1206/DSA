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
        int di = INT_MIN;
        diam(root, di);
        return di;
    }

private:
    int diam(node *p, int &maxi)
    {
        if (p != NULL)
        {
            int a = diam(p->left, maxi), b = diam(p->right, maxi);
            int d = a + b + p->data;
            int ms = max(p->data + max(a, b), p->data);
            d = max(ms, d);
            maxi = max(d, maxi);
            return ms;
        }
        return 0;
    }
};

int main()
{
    struct node *root = new node(2);
    root->left = new node(1);
    root->right = new node(-5);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->left->right->left = new node(6);
    // root->right->left = new node(7);
    // root->right->right = new node(8);
    // root->right->right->left=new node(9);
    // root->right->right->right = new node(10);

    // root->left = new node(9);
    // root->right = new node(20);
    // root->right->left = new node(15);
    // root->right->right = new node(7);
    demo s;
    cout << "No of Nodes in Binary tree is " << s.diameter(root) << endl;
}