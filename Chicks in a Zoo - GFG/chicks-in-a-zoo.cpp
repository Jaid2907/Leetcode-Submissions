//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    long long int curr = 1;
	    vector<long long int> dp(n+1);
	    dp[1] = 1;
	    
	    for(int i = 2; i<=n; i++){
	       
	        if(i-6 >= 1)
	            curr -= dp[i-6];
	       long long int newborn = curr*2;
	       curr =  curr + curr* 2;
	       dp[i] = newborn;
	    }
	    
	    return curr;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends