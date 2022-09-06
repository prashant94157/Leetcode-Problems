class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
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
        for(int i=n-1;i>=0;i--)
        {
            while(s.size() && s.top()<=nums[i])
                s.pop();
            
            nge[i] = s.size() ? s.top() : -1;
            
            s.push(nums[i]);
        }
        return nge;
    }
};