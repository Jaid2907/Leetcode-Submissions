class Solution {
public:
    int n;
    int helper (int i, vector<int>& nums, int last_picked, bool greater,vector<vector<vector<int>>>& dp ){
        
        if(i == nums.size())
            return 0;
        
        int a = INT_MIN, b = INT_MIN;
        
        if(dp[i][last_picked][greater] != -1)
            return dp[i][last_picked][greater];
        
        //Pick
        if(last_picked == n)
         a = max(1 + helper(i+1,nums,i,false,dp), 1 + helper(i+1,nums,i,true,dp) );
        
        else if (greater && nums[i]<nums[last_picked]){
            a = 1 + helper(i+1,nums,i,false,dp);
        }
        
        else if(!greater && nums[i]>nums[last_picked]){
            a = 1 + helper(i+1,nums,i,true,dp);
        }
        
        
        b = helper(i+1,nums,last_picked, greater,dp);
        
        return  dp[i][last_picked][greater] = max(a,b);
    }
    int wiggleMaxLength(vector<int>& nums) {
        
        this->n = nums.size();
        vector<vector<vector<int>>> dp (this->n+1, vector<vector<int>>(this->n+1, vector<int>(2,-1)));
        return helper (0,nums,n,false,dp);
    }
};