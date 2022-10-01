class Solution {
    int dp[1000005];
    int recur(int n)
    {
        if(n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        if(n%2==0)
        return dp[n] = 1 + recur(n/2);
        return dp[n] = 1 + recur(3*n + 1);
    }
public:
    Solution()
    {
        memset(dp,-1,sizeof(dp));
        dp[1] = 0;
        for(int i=2;i<=1000;i++)
        {
            if(dp[i]==-1)
                recur(i);
            cout<<dp[i]<<" ";
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> arr;
        for(int i=lo;i<=hi;i++)
        {
            arr.push_back({dp[i],i});
        }
        sort(arr.begin(),arr.end());
        return arr[k-1].second;
    }
};