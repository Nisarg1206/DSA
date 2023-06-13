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
        int x, y;
        if (p != NULL)
        {
            x = diam(p->left, maxi);
            y = diam(p->right, maxi);

            int ms = max(p->data, max(x, y) + p->data);
            int ms2 = max(ms, x + y + p->data);
            maxi = max(maxi, ms2);
            return ms;
        }
        return 0;
    }
};
int
main()
{
    struct node *root = new node(9);
    root->left = new node(6);
    root->right = new node(-3);
    root->right->left = new node(-6);
    root->right->right = new node(2);
    root->right->right->left = new node(2);
    root->right->right->left->right = new node(-6);
    root->right->right->left->left = new node(-6);
    root->right->right->left->left->left = new node(-6);
    demo s;
    cout << "No of Nodes in Binary tree is " << s.diameter(root) << endl;
}