class Solution {
    bool recur(string s,string p,int i,int j,vector<vector<int>> &dp)
    {
        if(i==-1 && j==-1)
            return true;
        if(j==-1 || i<-1)
            return false;
        if(dp[i+1][j+1] != -1)
            return dp[i+1][j+1];
        if(i>=0 && (s[i]==p[j] || p[j]=='?'))
            return dp[i+1][j+1] = recur(s,p,i-1,j-1,dp);
        if(p[j]=='*')
            return dp[i+1][j+1] = recur(s,p,i,j-1,dp) || recur(s,p,i-1,j,dp);
        return dp[i+1][j+1] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = true;
                else
                if(j==0)
                   dp[i][j] =  false;
                else
                if(i>=1 && (s[i-1]==p[j-1] || p[j-1]=='?'))
                     dp[i][j] = dp[i-1][j-1];
                else
                if(p[j-1]=='*')
                {
                    dp[i][j] = dp[i][j-1] || (i>0 ? dp[i-1][j] : false);
                }
                else
                 dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};