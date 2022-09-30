class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        int res = 0, n = A.size(), m = A[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; j++)
            {
                if (A[i][j] && i && j)
                    A[i][j] += min({A[i - 1][j - 1], A[i - 1][j], A[i][j - 1]}); 
                res += A[i][j];
            }        
        return res;
    
    }
};