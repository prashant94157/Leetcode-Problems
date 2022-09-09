/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
private:
    // void inorder(TreeNode *root,vector<int> &res)
    // {
    //     if(root==NULL)
    //         return;
    //     inorder(root->left,res);
    //     res.push_back(root->val);
    //     inorder(root->right,res);
    // }
    void inorder(TreeNode *root,vector<int> &res)
    {
        if(root==NULL)
            return;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            if(root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
    }
};