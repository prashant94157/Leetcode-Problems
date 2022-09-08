class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // sort(bills.begin(), bills.end());
        map<int,int> mp;
        mp[10]=0;
        mp[5]=0;
        mp[20]=0;
        for(auto a:bills)
        {
            if(a==10)
            {
                if(mp[5]>0)
                mp[5]--;
                else return false;
            }
            if(a==20)
            {
                if(mp[10] > 0 && mp[5] > 0)
                {
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>2)
                    mp[5]-=3;
                else return false;
            }
            mp[a]++;
        }
        return true;
    }
};