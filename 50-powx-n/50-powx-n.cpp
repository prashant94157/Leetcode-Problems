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
        double d = p(x*x, n/2);
        return (n%2 == 0) ? d : x*d;
    }
};