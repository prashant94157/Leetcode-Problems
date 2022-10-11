class Solution {
    long long recur(int i,vector<int> &arr,int sum,vector<vector<long long>> &dp)
    {
        if(i<0)
        return sum==0;
        if(sum<0)
        return 0;
        if(dp[i][sum] != -1)
        return dp[i][sum];
        dp[i][sum] = recur(i-1,arr,sum-arr[i],dp) + recur(i-1,arr,sum,dp);
        // dp[i][sum] %= 1000000007;
        return dp[i][sum];
    }
	public:
	int perfectSum(vector<int> &arr, int n, int sum)
	{
        vector<vector<long long>> dp(n,vector<long long> (sum+1,-1));
        return recur(n-1,arr,sum,dp);
	}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto a:nums)
            sum+=a;
        if((sum-target)%2!=0 || (sum-target)/2<0)
            return 0;
        cout<<sum<<endl;
        target = (sum-target)/2;
        return perfectSum(nums,nums.size(),target);
    }
};