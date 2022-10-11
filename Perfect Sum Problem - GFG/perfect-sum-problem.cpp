//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    long long recur(int i,int arr[],int sum,vector<vector<long long>> &dp)
    {
        if(i<0)
        return sum==0;
        if(sum<0)
        return 0;
        if(dp[i][sum] != -1)
        return dp[i][sum];
        dp[i][sum] = recur(i-1,arr,sum-arr[i],dp) + recur(i-1,arr,sum,dp);
        dp[i][sum] %= 1000000007;
        return dp[i][sum];
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // return recur(arr,n-1,sum);
        vector<vector<long long>> dp(n,vector<long long> (sum+1,-1));
        return recur(n-1,arr,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends