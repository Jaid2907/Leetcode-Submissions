class Solution {
public:
    int tribo(int n, vector<int>& dp )
    {
        if(n == 2)
            return dp[n] = 1;
        if(n<=1)
            return dp[n] = n;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = tribo(n-3,dp) + tribo(n-2,dp) + tribo(n-1,dp);
    }
    int tribonacci(int n) {
        
     vector<int> dp(n+4,-1);
        
        
        return tribo(n,dp);
    }
};