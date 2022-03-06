class Solution {
public:
    int mod = 1e9 +7;
    long long int totalWays (int picked, int delivered, int n, vector<vector<int>>& dp)
    {
        if(picked == n && delivered == n)
            return 1;
        
        if(picked > n || delivered > n || delivered > picked )
            return 0;
        
        if(dp[picked][delivered] != -1)
            return dp[picked][delivered];
        
        //Ways to pick
        long long int waysToPick = (n-picked) * totalWays(picked+1, delivered, n, dp);
        
        long long int waysToDeliver = (picked-delivered) * totalWays(picked,delivered+1,n,dp);
        
        long long int ans = (waysToPick % mod + waysToDeliver % mod) % mod;
        
        return dp[picked][delivered] = ans;
        
    }
    int countOrders(int n) {
        
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return totalWays(0,0,n,dp);
    }
};