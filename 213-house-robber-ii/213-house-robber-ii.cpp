class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        if(n == 3)
            return max(max(nums[0],nums[1]),nums[2]);
        vector<int> dp(n,-1);
        
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        
        for(int i=2; i<n; i++){
            if(i == n-1)
            {
                dp[i] = dp[i-1];
            }
            else
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        int a = dp[n-1];
        // cout<<a<<endl;
        fill(dp.begin(),dp.end(),-1);
            dp[0] = 0;
            dp[1] = nums[1];
            int flag = 0;
            for(int i=2; i<n; i++){
                if(i == n-1){
                    dp[i] = nums[i] + dp[i-2];
                    
                }
            
            else{
                
                    dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            }
                
            }
        int b = dp[n-1];
        // cout<<b<<endl;
        
        return max(a,b);
            
    }
};