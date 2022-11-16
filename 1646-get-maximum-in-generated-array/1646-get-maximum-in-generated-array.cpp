class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<2)
            return n;
        vector<int> arr(n+1);
        arr[0]=0;arr[1]=1;
        int res = 1;
        for(int i=0;i<n;i++)
        {
            if(2*i>n)
                break;
            arr[2*i] = arr[i];
            res = max(res,arr[2*i]);
            if(2*i + 1>n)
                break;
            arr[2*i + 1] = arr[i]+arr[i+1];
            res = max(res,arr[2*i + 1]);
        }
        return res;
    }
};