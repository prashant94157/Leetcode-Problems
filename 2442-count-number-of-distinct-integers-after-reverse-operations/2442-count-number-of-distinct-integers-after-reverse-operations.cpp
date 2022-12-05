class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for(auto a:nums)
        {
            s.insert(a);
            int num=0;
            while(a)
            {
                num = num*10 + a%10;
                a/=10;
            }
            s.insert(num);
        }
        return s.size();
    }
};