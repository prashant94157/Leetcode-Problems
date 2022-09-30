class Solution {
    int recur(vector<int>& arr, int i,int j,vector<vector<int>> &dp)
    {
        if(i<0)
            return 0;
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        return dp[i][j] = max(arr[i]*j + recur(arr,i-1,j+1,dp),recur(arr,i-1,j,dp));
    }
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        int n = arr.size();
        vector<vector<int>> dp(n+5,vector<int> (n+5,INT_MIN));
        // for()
        return recur(arr, arr.size()-1, 1,dp);
    }
};