class Solution {
    double f(double x,long n)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 1/f(x,-n);
        double ans = f(x,n/2);
        if(n%2==0)
            return ans*ans;
        return ans*ans*x;
    }
public:
    double myPow(double x, int n) {
        return f(x,n);
    }
};