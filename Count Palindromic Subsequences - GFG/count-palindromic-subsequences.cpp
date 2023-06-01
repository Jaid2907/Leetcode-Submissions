//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
       //Your code here
        int n = s.size();
        long long int mod = 1e9 + 7;
        vector<vector<long long int>> dp(n, vector<long long int>(n,0));
        

        for(int i = 0; i<n; i++)
            dp[i][i] = 1;

        for(int i = n-1; i>=0; i--){
            
            for(int j = i+1; j<n; j++){
                
               
                if(s[i] == s[j]){
                    dp[i][j] = (1 + dp[i][j-1]  + dp[i+1][j] )%mod;
                }
                else{
                     dp[i][j] = (dp[i+1][j] - dp[i+1][j-1] + dp[i][j-1] + mod)%mod;
                }

                
            }
        }
        
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }


        return dp[0][n-1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends