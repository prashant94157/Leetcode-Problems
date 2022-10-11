class Solution {
    // int recur(int amount,int i,vector<int> &coins,vector<vector<int>> &dp)
    // {
    //     if(amount<0)
    //         return 0;
    //     if(i==0)
    //     {
    //         return amount%coins[i]==0;
    //     }
    //     if(dp[i][amount] != -1)
    //         return dp[i][amount];
    //     return dp[i][amount] = recur(amount-coins[i],i,coins,dp) + recur(amount,i-1,coins,dp);
    // }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        // return recur(amount,n-1,coins,dp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0)
                    dp[i][j] = j%coins[i]==0;
                else {
                    if(j-coins[i] >=0)
                    dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][amount];
    }
};