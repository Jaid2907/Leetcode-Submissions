//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int n) {
        //Write your code here
        vector<int> dp(n+1,0);
        cost.push_back(0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2; i<=n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        return dp[n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends