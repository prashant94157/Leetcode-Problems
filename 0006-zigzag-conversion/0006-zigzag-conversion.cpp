class Solution {
public:
    string convert(string s, int n) {
        if(n==1)
            return s;
        vector<string> arr(n);
        int i=0,state=0;
        for(auto a:s)
        {
            if(state==0 || i==0)
            {
                arr[i]+=a;
                i++;
                if(i==n)
                {
                    i-=2;
                    state=1;
                }
            }
            else
            {
                arr[i]+=a;
                i--;
                if(i==0)
                {
                    i=0;
                    state=0;
                }
            }
        }
        string str;
        for(auto a:arr)
        {
            str+=a;
        }
        return str;
    }
};