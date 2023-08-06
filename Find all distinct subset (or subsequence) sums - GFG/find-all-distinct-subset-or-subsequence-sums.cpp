//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    int sum = accumulate(nums.begin(), nums.end(), 0);
	    int n = nums.size();
	    vector<vector<bool>> dp(n+1, vector<bool>(sum+1,0));
	    dp[0][0] = true;
	    
	    for(int i = 1; i<=n; i++){
	        for(int j = 0; j<=sum; j++){
	            dp[i][j] = dp[i-1][j];
	            if(j-nums[i-1] >= 0)
	                dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
	        }
	    }
	    
	    vector<int> ans;
	    
	    for(int j = 0; j<=sum; j++){
	        for(int i = 0; i<=n; i++){
	            if(dp[i][j]){
	                ans.push_back(j);
	                break;
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends