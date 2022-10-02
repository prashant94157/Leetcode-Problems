class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res=0,n=target.size();
        for(int i=1;i<n;i++)
        {
            if(target[i]>target[i-1])
                res+=target[i]-target[i-1];
        }
        return res+target[0];
    }
};