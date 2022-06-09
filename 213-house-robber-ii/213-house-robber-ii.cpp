class Solution {
public:
    //Solving as two house robber problems
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        if(n == 3)
            return *max_element(nums.begin(),nums.end());
        vector<int> dp(n,-1);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        //First leg from 0 to n-1 houses
        for(int i=2; i<n-1; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
        int ans1 = dp[n-2];
        
        //second leg from 1 to n houses
        fill(dp.begin(),dp.end(),-1);
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        
        for(int i=3; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int ans2 = dp[n-1];
        
        return max(ans1, ans2);
        
    }
};