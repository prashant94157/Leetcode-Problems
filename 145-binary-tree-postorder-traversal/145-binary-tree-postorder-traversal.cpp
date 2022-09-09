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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     postorder(root,res);
    //     return res;
    // }
    // void postorder(TreeNode *root,vector<int> &res)
    // {
    //     if(root==NULL)
    //         return;
    //     postorder(root->left, res);
    //     postorder(root->right, res);
    //     res.push_back(root->val);
    // }
//     void postorder(TreeNode *root,vector<int> &res)
//     {
//         if(root==NULL)
//             return;
//         stack<TreeNode*> st1, st2;
//         st1.push(root);
//         while(!st1.empty())
//         {
//             root = st1.top();
//             st1.pop();
//             st2.push(root);
//             if(root->left)
//                 st1.push(root->left);
//             if(root->right)
//                 st1.push(root->right);
            
//         }
//         while(!st2.empty())
//         {
//             res.push_back(st2.top()->val);
//             st2.pop();
//         }
//     }
    
    
    
    
//     int n;
//     vector<int> postorderTraversal(TreeNode* root) {
        
//         n= size(root);
//         vector<int> res(n);
//         postorder(root,res);
//         return res;
//     }
//     int size(TreeNode *root)
//     {
//         if(root==NULL)
//             return 0;
//         return 1 + size(root->left) + size(root->right);
//     }
//     void postorder(TreeNode *root,vector<int> &res)
//     {
//         if(root==NULL)
//             return;
//         stack<TreeNode*> st1;
//         st1.push(root);
//         while(!st1.empty())
//         {
//             root = st1.top();
//             st1.pop();
//             res[--n] = root->val;
//             if(root->left)
//                 st1.push(root->left);
//             if(root->right)
//                 st1.push(root->right);
            
//         }
//     }
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
    void postorder(TreeNode* root, vector<int> &res)
    {
        if(root==NULL)
            return;
        TreeNode *previous = NULL, *curr = root;
        stack<TreeNode*> st;
        while(curr || !st.empty())
        {
            if(curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                previous = st.top()->right;
                if(previous)
                {
                    curr = previous;
                }
                else
                {
                    previous = st.top();st.pop();
                    res.push_back(previous->val);
                    while(!st.empty() && previous==st.top()->right)
                    {
                        previous = st.top();st.pop();
                        res.push_back(previous->val);
                    }
                }
            }
        }
    }
};