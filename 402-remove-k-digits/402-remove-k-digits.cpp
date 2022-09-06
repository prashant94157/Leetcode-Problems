class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(auto a:num)
        {
            if(s.size()==0)
            {
                s.push(a);
            }
            else 
            {
                while(s.size() && k && s.top() > a)
                {
                    s.pop();k--;
                }
                s.push(a);
            }
        }
        while(k--)
            s.pop();
        if(s.size()==0)
            return "0";
        num = "";
        while(s.size())
        {
            num+=s.top();
            s.pop();
        }
        reverse(num.begin(), num.end());
        string res;
        int f=0;
        for(auto a:num)
        {
            if(f==0)
            {
                if(a=='0')
                    continue;
                else
                {
                    f=1;
                    res+=a;
                }
            }
            else res+=a;
        }
        return res.size()==0 ? "0" : res;
    }
};