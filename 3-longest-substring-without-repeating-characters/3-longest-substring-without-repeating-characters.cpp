class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,0);
        int i=0,j=0,res=0, n = s.size();
        while(j<n)
        {
            if(hash[s[j]])
            {
                while(hash[s[j]])
                {
                    hash[s[i]]=0;
                    i++;
                }
            }
            hash[s[j]] = 1;
            j++;
            res = max(res, j-i);
        }
        return res;
    }
};