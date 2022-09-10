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
bool fun(TreeNode* l,TreeNode* r)
{
    if(!l && !r)
        return true;
    if(!l || !r) return false;
    return (l->val==r->val) && fun(l->right,r->left) && fun(l->left,r->right);
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root || (!(root->left) && !(root->right)))
            return true;
        if(!(root->left) || !(root->right)) return false;
        return (root->left->val == root->right->val) && fun(root->left,root->right);
    }
};