class Solution {
    int recur(vector<int> &arr,int i,int k)
    {
        if(arr.size()==1)
            return arr[i];
        i = (i+k)%arr.size();
        // cout<<arr[i]<<endl;
        arr.erase(arr.begin()+i);
        i %= arr.size();
        return recur(arr,i,k);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n);
        int i=0;
        for(auto &a:arr)
            a = ++i;
        return recur(arr,0,k-1);
    }
};