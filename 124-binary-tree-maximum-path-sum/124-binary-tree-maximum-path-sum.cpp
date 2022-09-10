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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        func(root, res);
        return res;
    }
private: 
    int func(TreeNode* root, int &res)
    {
        if(root==NULL)
            return -1e9;
        int left = func(root->left, res);
        int right = func(root->right, res);
        int onePart = max(left,right) + root->val;
        int twoPart = left + right + root->val;
        int noPart = root->val;
        res = max(res , max(max(noPart, twoPart),onePart));
        return max(max(left + root->val, right+root->val),root->val);
        
    }
};