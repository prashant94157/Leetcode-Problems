class Solution {
    double fun(double x,long long n)
    {
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        if(n==-1)
            return 1/x;
        if(n==1)
            return x;
        if(n==0)
            return 1;
        // cout<<"vghcghh";
        if(n>0)
        {
            double res = fun(x,n/2);
            if(n%2)
            {
                return res*res*x;
            }
            return res*res;
        }
        double res=fun(x,n/2);
        if((-n)%2)
        {
            return res*res/x;
        }
        return res*res;
    }
public:
    double myPow(double x, int n) {
        return fun(x,(long long)n);
    }
};