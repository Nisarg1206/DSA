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

vector<int> preorder(node *p)
{
    stack<node *> st;
    vector<int> ans;
    while (p != NULL || !st.empty())
    {
        if (p != NULL)
        {
            ans.push_back(p->data);
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
    return ans;
}

vector<int> postorder(node *p)
{
    stack<node *> st;
    vector<int> ans;
    while (p != NULL || !st.empty())
    {
        if (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            node *temp = st.top()->right;
            if(temp==NULL)
            {
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                p = temp;
            }
        }
    }
    return ans;
}

vector<int> inorder(node *p)
{
    stack<node *> st;
    vector<int> ans;
    while (p != NULL || !st.empty())
    {
        if (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.top();
            ans.push_back(p->data);
            st.pop();
            p = p->right;
        }
    }
    return ans;
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
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);

    cout << "Pre-order Traversal is " << endl;
    vector<int> ans1 = preorder(root);
    int n = ans1.size();
    for (int i = 0; i < n; i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl
         << endl;

    cout << "In-order Traversal is " << endl;
    vector<int> ans = inorder(root);
    n = ans.size();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl
         << endl;
    cout << "Post-order Traversal is " << endl;
    vector<int> ans3 = postorder(root);
    n = ans3.size();
    for (int i = 0; i < n; i++)
    {
        cout << ans3[i] << " ";
    }
}