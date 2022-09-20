class Solution {
    int recur(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp)
    {
        if(i+1 == triangle.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(triangle[i+1][j] + recur(i+1,j,triangle,dp), triangle[i+1][j+1] + recur(i+1,j+1,triangle,dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        // return triangle[0][0] + recur(0,0,triangle,dp);    
        dp[0][0] = triangle[0][0];
        int res = dp[0][0];
        for(int i=1;i<n;i++)
        {
            int currRes = INT_MAX;
            for(int j=0;j<=i;j++)
            {
                if(i==j)
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else if(j>0)
                    dp[i][j] = min(dp[i-1][j-1] + triangle[i][j], triangle[i][j] + dp[i-1][j]);
                else dp[i][j] = triangle[i][j] + dp[i-1][j];
                currRes = min(dp[i][j], currRes);
            }
            res = currRes;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return res;
    }
};