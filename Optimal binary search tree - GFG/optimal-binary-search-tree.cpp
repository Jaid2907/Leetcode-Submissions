//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i = 0; i<n; i++)
            dp[i][i] = freq[i];
            
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                
                int constant = 0, mini = INT_MAX;
                
                for(int k = i; k<=j; k++)
                    constant += freq[k];
                    
                for(int k = i; k<=j; k++){
                    
                    int left = k-1 >=0 ? dp[i][k-1] : 0;
                    int right = k+1<n ? dp[k+1][j] : 0;
                    
                    // if(i == 3 && j == 4){
                    //     cout<<k <<" "<<left<<" "<<right<<" "<<constant<<endl;
                    // }
                    
                    mini = min(mini, left + right + constant);
                }
                dp[i][j] = mini;
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
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends