class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n = nums.size(), res=0;
        while(j<n)
        {
            if(k<0)
            {
                while(k<0)
                {
                    if(nums[i]==0)
                        k++;
                    i++;
                }
            }
            if(nums[j]==0)
                k--;
            j++;
            if(k>=0)
            res = max(res,j-i);
        }
        return res;
    }
};