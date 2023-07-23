#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;

        if(root==NULL)
        {
            return ans;
        }
        TreeNode* cur=root;

        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* prev=cur->left;

                while(prev->right!=NULL and prev->right!=cur)
                {
                    prev=prev->right;
                }

                if(prev->right==NULL)
                {
                    ans.push_back(cur->val);
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;

        if(root==NULL)
        {
            return ans;
        }
        TreeNode* cur=root;

        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* prev=cur->left;

                while(prev->right!=NULL and prev->right!=cur)
                {
                    prev=prev->right;
                }

                if(prev->right==NULL)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};

//TC is O(N) and SC is O(1)