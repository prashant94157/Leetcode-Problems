class Solution {
   
public:
    double myPow(double x, int n) {
        return pow(x,(long long)n);
    }
    double pow(double x, long long n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
};