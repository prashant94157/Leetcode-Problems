
class Solution {
    int recur(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp)
    {
        static int move[] = {-1,0,+1};
        if(i==grid.size()-1)
            return 0;
        int res = 0;
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        for(int m1=0;m1<3;m1++)
        {
            for(int m2=0;m2<3;m2++)
            {
                int x = j1+move[m1];
                int y = j2+move[m2];
                if(x>=0 && x<grid[0].size() && y>=0 && y<grid[0].size())  
                {
                    if(x!=y)
                    res = max(res, grid[i+1][x] + grid[i+1][y] + recur(grid,i+1,x,y, dp));
                    else res = max(res, grid[i+1][x] + recur(grid,i+1,x,y,dp));
                    // cout<<i<<" "<<x<<" "<<y<<" "<<res<<endl;
                }
            }
        }
        
        return dp[i][j1][j2] = res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m,-1)));
        return  grid[0][0] + grid[0][m-1] + recur(grid,0,0,m-1,dp);
    }
};

/*
[[4,1,5,7,1]
,[6,0,4,6,4]
,[0,9,6,3,5]]

*/