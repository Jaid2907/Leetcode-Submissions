//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans  = 0;
        
        for(int i = n-1; i>=0; i--){
            dp[i][m-1] = mat[i][m-1];
            ans = max(ans, dp[i][m-1]);    
        }
            
        for(int j = m-1; j>=0; j--){
            dp[n-1][j] = mat[n-1][j];
            ans = max(ans, dp[n-1][j]);
            
        }
            
        for(int i = n-2; i>=0; i--){
            for(int j = m-2; j>=0; j--){
                if(mat[i][j] == 0)
                    continue;
                int mini = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
                
                
                dp[i][j] = 1 + mini;
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends