class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        map<int, int> c;
        c[0] = 1;
        int psum = 0, res = 0;
        for (int i : A) {
            psum += i;
            res += c[psum - S];
            c[psum]++;
        }
        return res;
    }
};