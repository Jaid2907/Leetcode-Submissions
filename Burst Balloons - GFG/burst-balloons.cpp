//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int n, vector<int> &arr) {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        
       
        
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                
               for(int k = i; k<=j; k++){
                
                //k is the last to be burst
                int left = k-1 >= 0 ? dp[i][k-1] : 0;
                int right = k+1<n ? dp[k+1][j] : 0;
                int lvalue = i-1>=0 ?  arr[i-1] : 1;
                int rvalue = j+1<n ? arr[j+1] : 1;
                dp[i][j] = max(dp[i][j], left + right + arr[k]*lvalue*rvalue);
                    
               }
               
               
            }
        }
        
       
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends