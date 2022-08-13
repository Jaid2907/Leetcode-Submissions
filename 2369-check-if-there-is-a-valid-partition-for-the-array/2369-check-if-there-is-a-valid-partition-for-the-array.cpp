class Solution {
public:
    bool helper(int i, vector<int>& nums,int n, vector<int>& dp){

        if(i == n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool res = false;
        if(i+1 < n && nums[i] == nums[i+1]){
            res = res || helper(i+2,nums,n,dp);
            
            if(i+2 < n && nums[i+2] == nums[i])
                res = res||helper(i+3,nums,n,dp);
            
        }
        
        if(i+2< n &&  nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1){
            res = res || helper(i+3,nums,n,dp);
        }
        
        return dp[i] = res;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return false;
        if(n == 2)
            return nums[0] == nums[1];
        
        vector<bool> dp(n,false);
        dp[0] = false;
        dp[1] = nums[0] == nums[1];
        dp[2] = (nums[2] == nums[1] && dp[1]) || (nums[2]-nums[1] == 1 && nums[1] - nums[0] == 1);
        
        
        for(int i = 3; i<n; i++){
            
            if(i-2 >=0 && nums[i] == nums[i-1]){
                dp[i] = dp[i] || dp[i-2];
                
                if(i-3>=0 && nums[i-1] == nums[i-2])
                    dp[i] = dp[i] || dp[i-3];
            }
            
            if(i-3 >=0 && nums[i]-nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1)
                dp[i] = dp[i] || dp[i-3];
        }
        
        
        return dp[n-1];
        
        
    }
};