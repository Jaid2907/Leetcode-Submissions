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
        int a = minCost(cost,0,n,dp);
        dp.resize(n+1,-1);
        int b = minCost(cost,1,n,dp);
        
        return min(a,b);
       
     
   
    }
};