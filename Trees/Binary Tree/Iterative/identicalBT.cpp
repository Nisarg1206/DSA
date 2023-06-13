#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *BuildBT(node *root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left of " << data << endl;
    root->left = BuildBT(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = BuildBT(root->right);
}

bool identicalBT(node *root1, node *root2)
{
    if(root2==NULL || root1==NULL)
        return (root1 == root2);

    else
    {
        if(root1->data == root2->data )
        {
            if(identicalBT(root1->left,root2->left) && identicalBT(root1->right,root2->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    // return (root1->data == root2->data) && identicalBT(root1->left, root2->left) && identicalBT(root1->right, root2->right);
}

int main()
{
    node *root1 = NULL, *root2 = NULL;

    cout << "Enter data for tree 1" << endl;
    root1 = BuildBT(root1);

    cout << "Enter data for tree 2" << endl;
    root2 = BuildBT(root2);

    if (identicalBT(root1, root2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1