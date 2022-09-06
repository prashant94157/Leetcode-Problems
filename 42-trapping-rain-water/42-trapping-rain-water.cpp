class Solution {
    vector<int> nextGreaterElements(vector<int> nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            while(s.size() && s.top()<=nums[i])
                s.pop();
            
            nge[i] = s.size() ? s.top() : -1;
            
            s.push(nums[i]);
        }
        return nge;
    }
    vector<int> great(vector<int> nums)
    {
        int n = nums.size();
        for(int i=n-2;i>=0;i--)
        {
            nums[i] = max(nums[i], nums[i+1]);
        }
        return nums;
    }
public:
    int trap(vector<int>& heights) {
        int n = heights.size(), res=0;
        vector<int> temp = heights;
        reverse(temp.begin(), temp.end());
        vector<int> left = great(temp), right = great(heights);
        reverse(left.begin(), left.end());
        for(int i=0;i<n;i++)
        {
            int m = min(left[i], right[i]);
            if(m !=-1)
            {
                res += m - heights[i];
            }
            // cout<<right[i]<<" ";
        }
        return res;
    }
};