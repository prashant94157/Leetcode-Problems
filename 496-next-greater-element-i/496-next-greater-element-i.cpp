class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int> ngtr;
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            while(s.size() && s.top()<=nums2[i])
                s.pop();
            if(s.size()==0)
                ngtr[nums2[i]] = -1;
            else
                ngtr[nums2[i]] = s.top();
            
            s.push(nums2[i]);
        }
        vector<int> res(nums1.size());
        int i=0;
        for(auto a:nums1)
            res[i++] = ngtr[a];
        return res;
    }
};