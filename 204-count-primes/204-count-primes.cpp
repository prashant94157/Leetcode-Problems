class Solution {
public:
    int countPrimes(int n) {
        vector<int> arr(n+5,0);
        int res=0;
        for(int i=2*2;i<n;i+=2)
        {
            arr[i] = 1;
        }
        for(int i=3;i*i<n;i+=2)
        {
            if(arr[i]==0)
            {
                for(int j=i*i;j<=n;j+=i)
                arr[j] = 1;
            }
        }
        for(int i=2;i<n;i++)
        {
            if(arr[i]==0)
            res++;
            // cout<<i<<" "<<arr[i]<<"\n";
        }
        return res;
    }
};