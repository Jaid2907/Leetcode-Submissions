class Solution {
public:
    int helper (int i, int k,int n, vector<int>& nums,vector<int>& dp){
        
        if(i == n){
            return 0;
        }
        if(dp[i] != -1)
            return dp[i];
        int maxi = INT_MIN;
        int ans = INT_MIN;
        
        for(int j = i; j<i+k && j<n; j++){
            
            maxi = max(maxi, nums[j]);
            ans = max(ans,  maxi*(j-i+1) + helper(j+1,k,n,nums,dp));
        }
        
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        dp[n-1] = arr[n-1];
        
        for(int i = n-2; i>=0; i--){
            int maxi = INT_MIN;
            int ans = INT_MIN;
            for(int j = i; j<i+k && j<n; j++){
                maxi = max(maxi, arr[j]);
                ans = max(ans, maxi*(j-i+1) + dp[j+1]);
            }
            
            dp[i] = ans;
        }
        
        return dp[0];
    }
};