class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                    mat[i][j] = -1;
                else q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if(i>0 && mat[i-1][j]==-1)
            {
                mat[i-1][j] = 1+mat[i][j];
                q.push({i-1,j});
            }
            if(j>0 && mat[i][j-1]==-1)
            {
                mat[i][j-1] = 1+mat[i][j];q.push({i,j-1});
            }
            if(i+1<n && mat[i+1][j]==-1)
            {
                mat[i+1][j] = 1+mat[i][j];q.push({i+1,j});
            }
            if(j+1<m && mat[i][j+1]==-1)
            {
                mat[i][j+1] = 1+mat[i][j];q.push({i,j+1});
            }
        }
        return mat;
    }
};