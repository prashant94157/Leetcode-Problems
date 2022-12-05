bool cmp(const string a,const string b)
{
    return a.size()<b.size();
}
class Solution {
    bool check(string a,string b)
    {
        int c=0;
        for(int i=0,j=0;j<b.size() && i<a.size();i++,j++)
        {
            if(a[i]!=b[j])
                c++,i--;
            if(c==2)
                return false;
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        int n=nums.size();
        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i].size() + 1==nums[j].size() && check(nums[i],nums[j]) && dp[i]+1>dp[j])
                    dp[j] = dp[i]+1;
            }
            res = max(res,dp[i]);
            cout<<nums[i]<<" "<<res<<endl;
        }
        return res;
    }
};