class Solution {
   
public:
    double myPow(double x, int n) {
        return p(x,(long long)n);
    }
    double p(double x, long long n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? p(x*x, n/2) : x*p(x*x, n/2);
    }
};