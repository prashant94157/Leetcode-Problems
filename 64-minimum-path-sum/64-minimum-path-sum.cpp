// int minPath(vector<vector<int>> &grid,vector<vector<int>> &res,int r=0,int c=0)
// {
//     if(r==grid.size() || c==grid[0].size())
//     return -1;
//     if(r==grid.size()-1 && c==grid[0].size()-1)
//     return grid[r][c];
//     if(res[r][c]!=-1)
//     return res[r][c];
//     int a=0,b=0;
//     a=minPath(grid,res,r+1,c);
//     b=minPath(grid,res,r,c+1);
//     if(a!=-1 && b!=-1)
//     res[r][c] = min(a,b)+grid[r][c];
//     else if(a!=-1) res[r][c] = a+grid[r][c];
//     else if(b!=-1) res[r][c] = b+grid[r][c];
//     else res[r][c] = grid[r][c];
//     return res[r][c];
// }
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size(), n = grid.size();
        vector<vector<int>> res(n,vector<int> (m,0));
        // return minPath(grid,res);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ans = 1e9;
                if(i==0 || j==0)
                {
                    if(i==0 && j==0)
                        res[i][j] = grid[i][j];
                    else if(j==0)
                        res[i][j] = grid[i][j] + res[i-1][j];
                    else res[i][j] = grid[i][j] + res[i][j-1];
                }
                else
                res[i][j] = min(res[i-1][j]+grid[i][j], res[i][j-1]+grid[i][j]);
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        return res[n-1][m-1];
    }
};