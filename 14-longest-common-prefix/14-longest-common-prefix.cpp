class Solution {
    string f(string a,string b)
    {
        string res="";
        int n = min(a.size(),b.size());
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[i])
            res+=a[i];
            else break;
        }
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for(auto a:strs)
        {
            res = f(a,res);
        }
        return res;
    }
};