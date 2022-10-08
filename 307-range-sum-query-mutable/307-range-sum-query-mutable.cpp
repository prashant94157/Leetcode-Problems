class NumArray {
    vector<int> seg;
    int n;
    void build(int ind,int low,int high,vector<int> &arr)
    {
        if(low==high)
        {
            seg[ind] = arr[low];return;
        }
        int mid = low + (high - low)/2;
        build(2*ind+1 , low , mid, arr);
        build(2*ind+2, mid +1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    void upd(int ind,int low,int high,int index,int val)
    {
        if(low==high)
        {
            seg[ind] = val;return;
        }
        if(index < low || index > high)
        {
            return;
        }
        int mid  = low + (high - low)/2;
        if(index <= mid)
        upd(2*ind + 1, low, mid, index, val);
        else 
        upd(2*ind + 2, mid+1, high, index,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    int sumR(int ind,int low,int high,int l,int r)
    {
        if(low>r || high<l)
            return 0;
        if(l<=low && high<=r)
            return seg[ind];
        int mid = low + (high - low)/2;
        int left = sumR(2*ind + 1,low,mid,l,r);
        int right = sumR(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        upd(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sumR(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */