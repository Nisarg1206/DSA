#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};
class Solution
{
    void parentChild(Node *root, Node *p, map<Node *, Node *> &m)
    {
        if (root == NULL)
        {
            return;
        }

        m[root] = p;

        parentChild(root->left, root, m);

        parentChild(root->right, root, m);
    }

public:
    vector<int> distanceK(Node *root, Node *target, int k)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        map<Node *, Node *> m;
        parentChild(root, NULL, m);

        unordered_set<Node *> s;
        queue<Node *> q;

        int count = 1;
        q.push(target);

        while (!q.empty() and k)
        {
            k--;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                root = q.front();
                q.pop();
                s.insert(root);
                if (!s.count(root->left) && root->left)
                {
                    q.push(root->left);
                }
                if (!s.count(root->right) and root->right)
                {
                    q.push(root->right);
                }
                if (!s.count(m[root]) and m[root])
                {
                    q.push(m[root]);
                }
            }
        }

        while (!q.empty())
        {
            root = q.front();
            q.pop();
            ans.push_back(root->data);
        }

        return ans;
    }
};