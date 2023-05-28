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

vector<int> allTraversal(node *p)
{
    stack<pair<node *, int>> st;
    vector<int>pre,post,in;
    st.push({p, 1});
    while(!st.empty())
    {
        auto i = st.top();
        st.pop();
        if(i.second==1)
        {
            pre.push_back(i.first->data);
            i.second++;
            st.push(i);
            
            if(i.first->left!=NULL)
            {
                st.push({i.first->left, 1});
            }
        }
        else if(i.second==2)
        {
            in.push_back(i.first->data);
            i.second++;
            st.push(i);
            
            if(i.first->right!=NULL)
            {
                st.push({i.first->right, 1});
            }
        }
        else
        {
            post.push_back(i.first->data);
        }
        
    }
    return in;
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
    vector<int> p = allTraversal(root);
    int n = p.size();
    for (int i = 0; i < n;i++)
    {
        cout << p[i] << " ";
    }
}