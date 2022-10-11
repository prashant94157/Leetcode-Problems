// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string B= A;
        reverse(B.begin(),B.end());
        int n = A.size() , res[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0 || i==0)
                res[i][j] = 0;
                else if(A[i-1] == B[j-1])
                res[i][j] = 1+res[i-1][j-1];
                else res[i][j] = max(res[i-1][j], res[i][j-1]);
            }
        }
        return res[n][n];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends