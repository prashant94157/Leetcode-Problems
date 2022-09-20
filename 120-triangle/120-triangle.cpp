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
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return triangle[0][0] + recur(0,0,triangle,dp);        
    }
};