class Solution {
    vector<int> nsl(vector<int> arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            int a = arr[i];
            if(s.size()==0)
            {
                res[i] = -1;
            }
            else if(arr[s.top()] < a)
                res[i] = s.top();
            else
            {
                while(s.size() && arr[s.top()]>=a)
                    s.pop();
                if(s.size()==0)
                    res[i] = -1;
                else 
                    res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
    vector<int> nsr(vector<int> arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--)
        {
            int a = arr[i];
            if(s.size()==0)
            {
                res[i] = n;
            }
            else if(arr[s.top()] < a)
                res[i] = s.top();
            else
            {
                while(s.size() && arr[s.top()]>=a)
                    s.pop();
                if(s.size()==0)
                    res[i] = n;
                else 
                    res[i] = s.top();
            }
            s.push(i);
        }
        return res;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left, right;
        left = nsl(heights);
        right = nsr(heights);
        int res = 0, n = heights.size();
        for(int i=0;i<n;i++)
        {
            int currRes = heights[i]*(right[i] - left[i] - 1) ;
            res = max(res, currRes);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), res=0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                heights[j]++;
                else heights[j] = 0;
                cout<<heights[j]<<" ";
            }
            cout<<endl;
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
};