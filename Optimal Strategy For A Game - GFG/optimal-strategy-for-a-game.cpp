//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n,0));
        
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                if(j-i == 0){
                    dp[i][j] = arr[i];
                }
                else if(j-i == 1){
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else{
                    dp[i][j] = max(arr[i] + min(dp[i+2][j],dp[i+1][j-1]), arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
                }
            }
        }
        
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends