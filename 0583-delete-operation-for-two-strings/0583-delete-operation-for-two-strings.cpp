class Solution {
    int func(string s,string p)
    {
        int m=p.size(),n=s.size();
        vector<vector<int>> res(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1])
                {
                    res[i][j]=res[i-1][j-1] + 1;
                }
                else
                {
                    res[i][j] = max(res[i-1][j] , res[i][j-1]);
                }
            }
        }
        return (n + m - 2*res[n][m]);
    }
public:
    int minDistance(string word1, string word2) {
        return func(word1,word2);
    }
};