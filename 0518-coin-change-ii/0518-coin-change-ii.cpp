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
        vector<int> prev(amount+1,-1);
        // return recur(amount,n-1,coins,dp);
        for(int i=0;i<n;i++)
        {
            vector<int> curr(amount+1,-1);
            for(int j=0;j<=amount;j++)
            {
                if(i==0)
                    curr[j] = j%coins[i]==0;
                else {
                    if(j-coins[i] >=0)
                    curr[j] = curr[j-coins[i]] + prev[j];
                    else curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[amount];
    }
};