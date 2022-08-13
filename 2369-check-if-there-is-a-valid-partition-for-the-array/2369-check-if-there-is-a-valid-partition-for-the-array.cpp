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
        
        // vector<bool> dp(n,false);
        bool curr_3, curr_2,curr_1;
        curr_3 = false;
        curr_2 = nums[0] == nums[1];
        curr_1 = (nums[2] == nums[1] && curr_2) || (nums[2]-nums[1] == 1 && nums[1] - nums[0] == 1);
        
        
        for(int i = 3; i<n; i++){
            bool curr = false;
            
            if(i-2 >=0 && nums[i] == nums[i-1]){
                curr = curr || curr_2;
                
                if(i-3>=0 && nums[i-1] == nums[i-2])
                    curr = curr || curr_3;
            }
            
            if(i-3 >=0 && nums[i]-nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1)
                curr = curr || curr_3;
            
           curr_3 = curr_2;
           curr_2 = curr_1;
           curr_1 = curr;
        }
        
        
        return curr_1;
        
        
    }
};