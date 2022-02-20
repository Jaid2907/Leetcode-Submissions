class Solution {
public:
    int climb(int n, vector<int>& dp)
    {
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        
        
        int left = climb(n-1,dp);
        int right = climb(n-2,dp);
        dp[n] = left+right;
        
        return left + right;
        
    }
    int climbStairs(int n) {
        
        
        vector<int> dp(n+1,-1);
        
        return climb(n,dp);;
        
    }
};