class Solution {
    int n;
    int recur(vector<vector<int>>& matrix, int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || i>=n || j>=n || j<0)
            return 1e9;
        if(i==n-1)
            return matrix[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int a = recur(matrix,i+1,j-1,dp), b = recur(matrix,i+1,j,dp), c = recur(matrix,i+1,j+1,dp);
        return dp[i][j] = matrix[i][j] + min(min(a,b),c) ;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();int res = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n,-1));
        for(int i=0;i<n;i++)
        {
            res = min(recur(matrix, 0,i,dp),res);
        }
        return res;
    }
};