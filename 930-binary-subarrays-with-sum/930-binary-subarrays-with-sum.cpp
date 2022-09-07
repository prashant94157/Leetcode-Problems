class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        mp[0] = 1;
        int currSum=0, res=0;
        for(auto a:nums)
        {
            currSum+=a;
            res += mp[currSum - goal];
            mp[currSum]++;
        }
        return res;
    }
};