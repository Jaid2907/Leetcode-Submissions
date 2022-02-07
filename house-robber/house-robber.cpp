class Solution {
public:
    int robHouse(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index == 0)
            return nums[0];
        if(index == 1)
            return max(nums[0],nums[1]);
        if(dp[index] != -1)
            return dp[index];
        
        int pick = INT_MIN;
        int notPick = INT_MIN;
        //Pick 
        
         pick = nums[index] + robHouse(nums,index-2,dp);
        //Not Pick
         notPick = robHouse(nums,index-1,dp);
        
        dp[index] = max(pick, notPick);
        
        return dp[index];
    }
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        
        return robHouse(nums,nums.size()-1,dp);
        
    }
};