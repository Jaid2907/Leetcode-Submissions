class Solution {
public:
    int helper (int target, vector<int>& nums, vector<int>& dp){

    if(target == 0){
        return 0;
    }
    if(dp[target] != -1)
        return dp[target];
    
    int ans = INT_MAX;
    for(int i=0; i<nums.size(); i++){
        if(target-nums[i]>=0)
        ans =  min(ans,helper(target-nums[i],nums,dp));
    }
    
    if(ans == INT_MAX)
        return dp[target] = INT_MAX;
    return dp[target] = ans+1;
}
    int coinChange(vector<int>& num, int x) {
    vector<int> dp(x+1,-1);
    int ans = helper(x,num,dp);
    if(ans == INT_MAX)
        return -1;
    return ans;
    }
};