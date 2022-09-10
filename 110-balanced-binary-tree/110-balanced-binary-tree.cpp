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
    int balanced(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int l = balanced(root->left);
        if(l==-1)
            return -1;
        int r = balanced(root->right);
        if(r==-1)
            return -1;
        if(abs(r-l)>1)
            return -1;
        return 1 + max(r,l);
    }
public:
    bool isBalanced(TreeNode* root) {
        return (balanced(root) != -1);
    }
};