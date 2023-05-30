//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int nums[])
    {
        // code here
        n--;
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        
        for(int i = 0; i<n; i++)
            dp[i][i] = 0;
        
            
        for(int i = n-2; i>=0; i--){
            
            for(int j =i+1 ; j<n; j++){
                
                for(int k = i; k<=j-1; k++){
                    
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + nums[i]*nums[k+1]*nums[j+1]);
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

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends