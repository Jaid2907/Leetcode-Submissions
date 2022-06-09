class Solution {
public:
   int minCost(vector<int>& cost, int i, int n, vector<int>& dp)
   {
       if(i>=n)
           return 0;
       if(dp[i] != -1)
           return dp[i];
       
       int oneStep = cost[i] + minCost(cost,i+1,n,dp);
       int twoStep = cost[i] + minCost(cost,i+2,n,dp);
       
       return dp[i] = min(oneStep,twoStep);
           
   }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
       
     
   
    }
};