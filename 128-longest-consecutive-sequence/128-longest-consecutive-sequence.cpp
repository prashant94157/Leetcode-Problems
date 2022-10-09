class DSU{
    map<int,int> size,parent;
    public:
    DSU(vector<int> &nums)
    {
        for(auto i:nums)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_set(int a)
    {
        if(parent[a]==a)
            return a;
        return parent[a] = find_set(parent[a]);
    }
    void union_set(int a,int b)
    {
        if(parent.find(a) == parent.end())
            return;
        a = find_set(a);
        b = find_set(b);
        if(a!=b)
        {
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int cons()
    {
        int m = 0;
        for(auto a:size)
        {
            m = max(a.second,m);
        }
        return m;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu(nums);
        for(auto a:nums)
        {
            dsu.union_set(a-1,a);
            dsu.union_set(a+1,a);
        }
        return dsu.cons();
    }    
};