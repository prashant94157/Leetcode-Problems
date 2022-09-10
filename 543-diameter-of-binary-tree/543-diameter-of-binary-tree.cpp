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
    int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        func(root);
        return res;
    }
    int func(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l = func(root->left);
        int r = func(root->right);
        res = max(res,l+r);
        return 1 + max(l,r);
    }
};