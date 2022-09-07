class Solution {
    int fun(string s,int k,char ch)
    {
        int i=0,j=0,res=INT_MIN,n=s.size();
        while(j<n)
        {
            if(k>=0)
            {
                if(s[j]!=ch)
                {
                    k--;
                }
                j++;
                if(k>=0)
                res=max(res,j-i);
            }
            else
            {
                if(s[i]!=ch)
                {
                    k++;
                }
                i++;
            }
        }
        return res;
    }
public:
    int characterReplacement(string s, int k) {
        int r=INT_MIN;
        for(int i=0;i<26;i++)
        {
            r=max(fun(s,k,'A'+i),r);
        }
        return r;
    }
};