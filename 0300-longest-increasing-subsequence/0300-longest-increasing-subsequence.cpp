class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<nums[j] && dp[i]+1>dp[j])
                    dp[j] = dp[i]+1;
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};