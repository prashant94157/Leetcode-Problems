class Solution {
    priority_queue<int,vector<int>,greater<int>> q;
    int s;
public:
    int findKthLargest(vector<int>& nums, int k) {
        s=k;
        for(int a:nums)
        {
            q.push(a);
            if(q.size()>s)
                q.pop();
        }
        return q.top();
    }
};