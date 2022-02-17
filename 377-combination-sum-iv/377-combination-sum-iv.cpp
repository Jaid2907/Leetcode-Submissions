class Solution {
public:
     int combination ( int target, vector<int>& nums, vector<int>& dp)
    {
        if(target == 0)
        {
            return 1 ;
        }
        
        if(target<0 )
            return 0 ;
        
        
        if(dp[target] != -1)
            return dp[target];
         
         int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += combination(target-nums[i],nums,dp);
        }
        
        return dp[target] = sum;
        
       
    }
    int combinationSum4(vector<int>& nums, int target) {
     
        vector<int> dp(target+1, -1);
        
        return combination(target,nums,dp);
    }
};