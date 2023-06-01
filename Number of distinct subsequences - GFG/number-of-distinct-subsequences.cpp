//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.size();
	    unordered_map<char,int> mp;
	    vector<long long int> dp(n+1,0);
	    dp[0] = 1;
	    int mod = 1e9+7;
	    
	    for(int i = 0; i<n; i++){
	        char curr = s[i];
	        
	        if(mp.find(curr) != mp.end()){
	            (dp[i+1] = dp[i]*1ll*2 - dp[mp[curr]] + mod)%=mod;
	        }
	        else{
	            (dp[i+1] = dp[i]*1ll*2)%=mod;
	        }
	        
	        mp[curr] = i;
	    }
	    
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends