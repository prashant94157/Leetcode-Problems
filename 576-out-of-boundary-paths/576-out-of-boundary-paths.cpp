class Solution {
    int mod = 1000000007 ;
    int recur(int n,int m,int move,int i,int j,int dp[][55][55])
    {
        if(i<0 || j<0 || i==n || j==m)
            return 1;
        if(move==0)
            return 0;
        if(dp[i][j][move] != -1)
            return dp[i][j][move];
        int res = 0;
        res = (res + recur(n,m,move-1,i-1,j,dp))%mod;
        res = (res + recur(n,m,move-1,i+1,j,dp))%mod;
        res = (res + recur(n,m,move-1,i,j-1,dp))%mod;
        res = (res + recur(n,m,move-1,i,j+1,dp))%mod;
        return dp[i][j][move] = res;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[55][55][55];
        memset(dp,-1,sizeof(dp));
        return recur(m,n,maxMove,startRow,startColumn,dp);
    }
};