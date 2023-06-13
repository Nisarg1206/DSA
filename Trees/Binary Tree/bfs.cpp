#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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

// vector<vector<int>> LevelOrder(node *p)
// {
//     queue<node *> q;
//     vector<vector<int>> ans;
//     int k = 0, i = 0;
//     vector<int>temp;
//     q.push(p);
//     q.push(NULL);

//     while (!q.empty())
//     {
//         p = q.front();
//         q.pop();

//         if (p == NULL)
//         {
//             ans.push_back(temp);
//             temp.clear();
//             // k++;
//             // i = 0;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             temp.push_back(p->data);
//             // ans[k][i] = p->data;
//             // i++;
//             if (p->left != NULL)
//             {
//                 q.push(p->left);
//             }
//             if (p->right != NULL)
//             {
//                 q.push(p->right);
//             }
//         }
//     }
//     return ans;
// }

vector<vector<int>> LevelOrder(node *p)
{
    queue<node *> q;
    vector<vector<int>> ans;
    int k = 0, i = 0;
    vector<int>temp;
    q.push(p);
    q.push(NULL);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        if (p == NULL)
        {
            ans.push_back(temp);
            temp.clear();
            // k++;
            // i = 0;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            temp.push_back(p->data);
            // ans[k][i] = p->data;
            // i++;
            if (p->left != NULL)
            {
                q.push(p->left);
            }
            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
    }
    return ans;
}

// void LevelOrder(node *p)
// {
//     queue<node *> q;
//     q.push(p);
//     q.push(NULL);
//     while (!q.empty())
//     {
//         p = q.front();
//         q.pop();

//         if (p == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             cout << p->data << " ";
//             if (p->left != NULL)
//             {
//                 q.push(p->left);
//             }
//             if (p->right != NULL)
//             {
//                 q.push(p->right);
//             }
//         }
//     }
// }
void ReverseLevelOrder(node *p)
{
    queue<node *> q;
    stack<node *> s;
    q.push(p);
    q.push(NULL);
    while (!q.empty())
    {
        p = q.front();
        q.pop();

        if (p == NULL)
        {
            cout << endl;
            s.push(NULL);
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            s.push(p);
            if (p->left != NULL)
            {
                q.push(p->left);
            }
            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
    }

    while (!s.empty())
    {
        if (s.top() == NULL)
        {
            cout << endl;
            s.pop();
        }
        else
        {
            p = s.top();
            cout << p->data << " ";
            s.pop();
        }
    }
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);

    vector<vector<int>>ans= LevelOrder(root);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    // cout << endl;
    // ReverseLevelOrder(root);
}