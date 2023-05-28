//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        int mod = 1e9+7;
        if(n == 1)
            return k;
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        dp[2][0] = k;
        dp[2][1] = (k*1ll*(k-1))%mod;
        
        for(int i = 3; i<=n; i++){
           dp[i][0] = dp[i-1][1]%mod;
           dp[i][1] = ((dp[i-1][0] + dp[i-1][1])*1ll*(k-1))%mod;
        }   
        
        
        return (dp[n][0] + dp[n][1])%mod;
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends