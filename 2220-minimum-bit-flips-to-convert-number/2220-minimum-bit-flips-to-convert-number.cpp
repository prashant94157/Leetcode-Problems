class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=0;
        while(start || goal)
        {
            res += ((start&1)^(goal&1));
            start>>=1;
            goal>>=1;
        }
        return res;
    }
};