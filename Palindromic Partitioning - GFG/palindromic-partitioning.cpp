// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string& s){
        int n = s.size();
        
        for(int i = 0; i<n/2; i++){
            if(s[i] != s[n-1-i])
                return false;
        }
        
        return true;
    }
    int helper(string& s, int i,int n, vector<vector<int>>& dp, vector<int>& dp_1){
        
        if(i == n){
            return 0;
        }
        if(dp_1[i] != -1)
            return dp_1[i];
        int ans = INT_MAX;
        
        for(int j = i; j<n; j++){
            
            if(i>0 && j>0 && s[i] == s[j] && dp[i-1][j-1] == 1){
                dp[i][j] = 1;
                ans =  min (ans, 1 + helper(s,j+1,n,dp,dp_1));
            }
            string sub = s.substr(i,j-i+1);
            
            if(isPalindrome(sub)){
                dp[i][j] = 1;
                ans = min(ans, 1 + helper(s,j+1,n,dp,dp_1));
            }
            
        }
        
        return dp_1[i]  = ans;
    }
    
    int palindromicPartition(string s)
    {   int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n,false));

        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                if(j-i == 0){
                    pal[i][j] = true;
                }
                else if(j-i == 1){
                    pal[i][j] = s[i] == s[j];
                }
                else{
                    pal[i][j] = s[i] == s[j] && pal[i+1][j-1];
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(n,1e9));

        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                if(pal[i][j] || i == j){
                    dp[i][j] = 0;
                    continue;
                }

                for(int k = i; k<j; k++){

                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k+1][j]);
                }
            }
        }

        return dp[0][n-1];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends