//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int arr[], int n, int sum) {

        // code here.
        
        
        vector<long long int> dp(sum+1,0);
        dp[0] = 1;
        
        for(int i = 0; i<n; i++){
            
            for(int j = arr[i]; j<=sum; j++){
                dp[j] += dp[j-arr[i]];
            }
        }
        
        return dp[sum];
        
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends