//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int n){
        // code here
        if(n <= 3)
            return n;
        vector<pair<long long int,long long int>> dp(n+1);//{ans, copied}
        dp[1] = {1,0};
        dp[2] = {2,0};
        dp[3] = {3,0};
        
        for(int i = 4; i<=n; i++){
            long long int maxi = i;
            long long int paste = 0;
            
            for(int j = 1; j<=i-3; j++){
                
                if((i-j-1)*1ll*dp[j].first > maxi){
                    maxi = (i-j-1)*1ll*dp[j].first;
                    paste  = dp[j].first;
                }
            }
            if(dp[i-1].first + dp[i-1].second > maxi){
                maxi = dp[i-1].first + dp[i-1].second;
                paste = dp[i-1].second;
            }
            
            if(dp[i-2].first + 2*1ll*dp[i-2].second > maxi){
                maxi = dp[i-2].first + 2*1ll*dp[i-2].second;
                paste = dp[i-2].second;
            }
           
            dp[i] = {maxi,paste};
        }
        
        return dp[n].first;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends