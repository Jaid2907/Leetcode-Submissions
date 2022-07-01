class Solution {
public:
    int helper (int i, int last_picked_index, vector<int>& arr, int n,vector<vector<int>>& dp){
    if(i == n)
        return 0;
    
    if(dp[i][last_picked_index] != -1){
        return dp[i][last_picked_index];
    }
    
    if( last_picked_index == n || arr[i] > arr[last_picked_index]){
        return dp[i][last_picked_index] =  max(1 + helper(i+1,i,arr,n,dp), helper(i+1,last_picked_index,arr,n,dp));
    }
    else
        return dp[i][last_picked_index] =  helper(i+1,last_picked_index,arr,n,dp);
}
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return helper(0,n,nums,n,dp);
    }
    
};