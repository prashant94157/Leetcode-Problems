class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m =grid[0].size(), f=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    f=1;
            }
        }
        if(q.size()==0)
        {
            return -f;
        }
        f=0;
        // cout<<q.size()<<" ";
        int t = 0;
        while(q.size())
        {
            int sz = q.size(), f1=0;
            for(int ind=0;ind<sz;ind++)
            {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(grid[i][j]==2 && f==1)
                    continue;
                f1=1;
                grid[i][j] = 2;
                cout<<i<<" "<<j<<endl;
                if(i > 0 && grid[i-1][j]==1)
                    q.push({i-1,j});
                if(j > 0 && grid[i][j-1]==1)
                    q.push({i,j-1});
                if(i < n-1 && grid[i+1][j]==1)
                    q.push({i+1,j});
                if(j < m-1 && grid[i][j+1]==1)
                    q.push({i,j+1});
            }
            if(f1)
            t++;
            f=1;
            cout<<t<<"\n";
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1)
                    return -1;        
        return t-1;
    }
};