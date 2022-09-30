#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    bool canPartition(vector<int>& wt) {
        int sum=0;
    for(auto a:wt)
    sum+=a;
    if(sum%2)
    return 0;
    int n=wt.size();
    int c=sum/2;
    vector<bool> prev(c+1,0);
    for(int i=0;i<n+1;i++)
    prev[0]=1;
    for(int i=1;i<n+1;i++)
    {
        vector<bool> curr(c+1);
        curr[0] = 1;
        for(int j=0;j<c+1;j++)
        {
            if(j>=wt[i-1])
            {
                curr[j] = prev[j-wt[i-1]]||prev[j];
            }
            else curr[j]=prev[j];
        }
        prev = curr;
    }
    return prev[c];
    }
};