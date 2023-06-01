//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
 int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        int start = -1, end = -1, maxi = INT_MIN;
        
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                
                if(j-i == 0){
                    dp[i][j] = 1;
                }
                else if(j-i == 1){
                    dp[i][j] = s[i]==s[j] ? 2 : 0;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] > 0)
                        dp[i][j] = 2 + dp[i+1][j-1];
                }
                
                if(dp[i][j] >= maxi){
                    maxi = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        
        
        return s.substr(start,end-start+1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends