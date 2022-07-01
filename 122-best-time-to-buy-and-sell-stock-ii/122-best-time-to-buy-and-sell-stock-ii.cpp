class Solution {
public:
    int helper (int i, vector<int>& prices, bool bought,vector<vector<int>>& dp){
        
        if(i == prices.size())
            return 0;
        
        if(dp[i][bought] != -1)
            return dp[i][bought];
        
        if(bought){
            int a = INT_MIN, b = INT_MIN;
            
            a = helper (i+1,prices,bought,dp);
            
            bought = false;
            b = prices[i] + helper(i+1,prices,bought,dp);
            
            return dp[i][true] =  max(a,b);
        }
        else{
            int a = INT_MIN, b = INT_MIN;
            
            a = helper(i+1,prices,bought,dp);
            
            bought = true;
            b = -prices[i] + helper(i+1,prices,bought,dp);
            
            return dp[i][false] = max(a,b);

        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        
        return helper(0,prices,false,dp);
    
    }
    
};