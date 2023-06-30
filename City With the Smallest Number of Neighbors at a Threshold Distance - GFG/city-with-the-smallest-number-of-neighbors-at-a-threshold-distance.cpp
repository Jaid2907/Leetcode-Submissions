//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
                     
        
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        
        for(int i = 0; i<edges.size(); i++){
            dp[edges[i][0]][edges[i][1]] = edges[i][2];
            dp[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    
                    if(dp[i][k] != 1e9 && dp[k][j] != 1e9){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
        
        int cnt = 0, ans = -1;
        int mini = INT_MAX;
        
        for(int i = n-1; i>=0; i--){
            
            cnt = 0;
            for(int j = 0; j<n; j++){
                if(i == j)  
                    continue;
                
                if(dp[i][j] <= distanceThreshold)
                    cnt++;
            }
            
            if(cnt < mini){
                mini = cnt;
                ans = i;
            }
        }
        
        return ans;
        
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends