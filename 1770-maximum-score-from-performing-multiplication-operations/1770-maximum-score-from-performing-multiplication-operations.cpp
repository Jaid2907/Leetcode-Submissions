class Solution {
public:
    int helper (int i, int k,int& m, int& n, vector<int>& nums,vector<int>& multi,vector<vector<int>>& dp){
        
        if(k == m){
            return 0;
        }
        
        if(dp[i][k] != 1e9+7)
            return dp[i][k];
        
        int j = n-1+i-k;
        
        int a = nums[i]*multi[k] + helper(i+1,k+1,m,n,nums,multi,dp);
        int b = nums[j]*multi[k] + helper(i,k+1,m,n,nums,multi,dp);
        
        return dp[i][k] = max(a,b);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        
        vector<vector<int>> dp(m,vector<int>(m,1e9+7));
        return helper(0,0,m,n,nums,multipliers,dp);
    }
};