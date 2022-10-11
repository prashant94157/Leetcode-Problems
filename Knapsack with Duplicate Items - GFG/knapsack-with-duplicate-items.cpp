//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        

       vector<vector<int>> res(n+1, vector<int> (w+1,0));
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<w+1;j++)
           {
               if(i==0 || j==0)
               {
                   res[i][j]=0;
        
               }
               else if( j>= wt[i-1])
               {
                   res[i][j] = max(res[i-1][j] , val[i-1] + res[i][j-wt[i-1]]);
               }
               else res[i][j] = res[i-1][j];
           }
       }
       return res[n][w];
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends