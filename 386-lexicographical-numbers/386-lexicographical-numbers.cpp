class Solution {
    void dfs(int n,int num,vector<int> &res)
    {
        if(num>n) return;
        res.push_back(num);
        for(int i=0;i<10;i++)
        {
            dfs(n,num*10 + i,res);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<10;i++)
        dfs(n,i,res);
        return res;
    }
};