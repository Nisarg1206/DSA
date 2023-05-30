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
        int dia = 0;
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

            int d = height(p->left) + height(p->right) ;

            return max(d, max(x, y));
        }
        return 0;
    }
};

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
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);

    demo s;
    cout << "No of Nodes in Binary tree is " << s.diameter(root) << endl;
}