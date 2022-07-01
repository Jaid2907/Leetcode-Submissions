
class Solution {
public:
    int fees;
    int helper (int i, vector<int>& prices, bool bought,vector<vector<int>>& dp){
        
        if(i == prices.size())
            return 0;
        if(dp[i][bought] != -1)
            return dp[i][bought];
        
        if(bought){
            
            return dp[i][bought] =  max(helper(i+1,prices,bought,dp),prices[i] - fees + helper(i+1,prices,false,dp));
        }
        else{
            
            return dp[i][bought] = max(helper(i+1,prices,bought,dp), -prices[i] + helper(i+1,prices,true,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        this->fees = fee;
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int>(2,-1));
        return helper(0,prices,false,dp);
    }
};