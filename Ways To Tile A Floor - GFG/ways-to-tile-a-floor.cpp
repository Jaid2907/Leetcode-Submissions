//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long numberOfWays(long long n) {
        //code here
        vector<long long int> dp(n+1,0);
        
        dp[1] = 1;
        dp[2] = 2;
        int mod = 1e9+7;
        
        for(int i = 3; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        
        return dp[n];
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends