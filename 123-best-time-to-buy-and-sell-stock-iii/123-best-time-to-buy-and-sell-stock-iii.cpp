
class Solution {
public:
    static bool compare (int a, int b){
        return a>b;
    }
    
    int helper(int i, bool bought, vector<int>& prices, int trans_cnt,vector<vector<vector<int>>>& dp){
        
        
        
        
        if(i == prices.size())
            return 0;
        if(trans_cnt == 0)
            return 0;
        
        
        
        if(dp[i][bought][trans_cnt] != -1)
            return dp[i][bought][trans_cnt];
        
        if(bought){
            
            int a = INT_MIN, b = INT_MIN;
            
           
             a = helper(i+1,bought,prices,trans_cnt,dp);
            
            bought = false;
            trans_cnt--;
             b =  prices[i] + helper(i+1,bought,prices,trans_cnt,dp);
            
            return  dp[i][true][trans_cnt+1] = max(a,b);
        }
        else{
            int a = helper(i+1,bought, prices,trans_cnt,dp);
            
            bought = true;
            int b = -prices[i] + helper(i+1,bought,prices,trans_cnt,dp);
            
            return dp[i][false][trans_cnt] = max(a,b);
        }
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
      vector<vector<vector<int>>> dp (n,vector<vector<int>>(2, vector<int>(3,-1)));
       return helper(0,false,prices,2,dp);
    }
        

};