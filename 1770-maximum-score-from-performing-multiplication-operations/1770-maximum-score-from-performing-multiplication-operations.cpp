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
        
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        
        for(int i = m-1; i>=0; i--){//op
            
            for(int j = m-1; j>=0; j--){//left
             
                if(i>=j){
                    int right = n-1+j-i;
                    int a = nums[j]*multipliers[i] + dp[i+1][j+1];
                    int b = nums[right]*multipliers[i] + dp[i+1][j];
                    
                    dp[i][j] = max(a,b);
                }
            }
        }
        
        return dp[0][0];
       
    }
};