class Solution {
    // int n;
    // int recur(vector<vector<int>>& matrix, int i,int j,vector<vector<int>> &dp)
    // {
    //     if(i<0 || i>=n || j>=n || j<0)
    //         return 1e9;
    //     if(i==n-1)
    //         return matrix[i][j];
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int a = recur(matrix,i+1,j-1,dp), b = recur(matrix,i+1,j,dp), c = recur(matrix,i+1,j+1,dp);
    //     return dp[i][j] = matrix[i][j] + min(min(a,b),c) ;
    // }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res=INT_MAX;
        // vector<vector<int>> dp(n, vector<int> (n,0));
        vector<int> prev(n);
        for(int i=0;i<n;i++)
        {
            // int currRes = INT_MAX;
            vector<int> curr(n);
            for(int j=0;j<n;j++)
            {
                if(i==0)
                    curr[j] = matrix[i][j];
                else
                {
                    int a = 1e9, b = 1e9, c = 1e9;
                    if(j>0)
                        a = prev[j-1];
                    b = prev[j];
                    if(j<n-1)
                        c = prev[j+1];
                    curr[j] = matrix[i][j] + min(min(a,b),c) ;
                }
                if(i==n-1)
                res = min(curr[j], res);
            }
            prev = curr;
            // res = currRes;
        }
        return res;
    }
};