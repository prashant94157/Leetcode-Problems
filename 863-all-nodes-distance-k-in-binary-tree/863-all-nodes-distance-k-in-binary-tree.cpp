/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(root==NULL)
            return res;
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        while(!q.empty())
        {
            root = q.front();
            q.pop();
            if(root->left)
            {
                mp[root->left] = root;
                q.push(root->left);
            }
            if(root->right)
            {
                mp[root->right] = root;
                q.push(root->right);
            }
        }
        q.push(target);
        set<TreeNode*> s;
        while(!q.empty() && k)
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                root = q.front();
                q.pop();
                s.insert(root);
                if(root->left && s.find(root->left) == s.end())
                {
                    q.push(root->left);
                }
                if(root->right && s.find(root->right) == s.end())
                {
                    q.push(root->right);
                }
                if(mp[root] && s.find(mp[root]) == s.end())
                q.push(mp[root]);
            }
            k--;
            // cout<<q.size()<<" ";
        }
        if(k==0)
        {
            while(!q.empty())
            {
                res.push_back(q.front()->val);
                q.pop();
            }
        }
        return res;
    }
};