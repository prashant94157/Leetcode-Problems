class Solution {
    // double recur(string s,string t,int i,int j,vector<vector<double>> &dp)
    // {
    //     if(j==0)
    //         return 1;
    //     if(i==0)
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     if(s[i-1]!=t[j-1])
    //         return dp[i][j] = recur(s,t,i-1,j,dp);
    //     return dp[i][j] = recur(s,t,i-1,j,dp) + recur(s,t,i-1,j-1,dp);
    // }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n+1,vector<double> (m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else
                if(i==0)
                    dp[i][j] = 0;
                else
                if(s[i-1]!=t[j-1])
                    dp[i][j] = dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};