//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int n = str.size();
		    vector<int> dp(n+1,0);
		    dp[0] = 1;
		    dp[1] = 1;
		    int mod = 1e9+7;
		    
		    for(int i = 2; i<=n; i++){
		        char curr = str[i-1];
		        
		        if(curr != '0')
		        (dp[i] += dp[i-1])%=mod;
		        
		        if(i-2>=0 && str[i-2] != '0'){
		            char prev = str[i-2];
		            string s = "";
		            s += prev;
		            s += curr;
		            int num = stoi(s);
		            if(num >=1 && num<=26){
		                (dp[i] += dp[i-2])%=mod;
		            }
		                
		        }
		    }
		    
		    return dp[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends