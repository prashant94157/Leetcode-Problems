//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    string f(string s,string p)
    {
        int n = min((int)s.size(),(int)p.size());
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==p[i])
            res+=s[i];
            else return res;
        }
        return res;
    }
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string res = arr[0];
        for(int i=1;i<N;i++)
        {
            res = f(res,arr[i]);
        }
        return res.size()==0 ? "-1" : res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends