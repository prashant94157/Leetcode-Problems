class Solution {
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
            return;
        grid[i][j] = 0;
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int i,j;
        n=grid.size();
        m =grid[0].size();
        for(i=0;i<n;i++)
        {
            dfs(i,0,grid);
            dfs(i,m-1,grid);
        }
        for(i=0;i<m;i++)
        {
            dfs(0,i,grid);
            dfs(n-1,i,grid);
        }
        int sum=0;
        for(auto a:grid)
        {
            for(auto b:a)
                sum+=b;
        }
        return sum;
    }
};