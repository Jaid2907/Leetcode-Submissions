class Solution {
public:
   int profitMaximisation (vector<int>& prices, int i, bool bought, int buying_price, vector<vector<vector<int>>>& dp)
   {    if(i==prices.size()-1 && bought)
            return prices[i]-buying_price;
       if(i>=prices.size())
            return 0;
    
        if(dp[i][bought][buying_price] != -1)
            return dp[i][bought][buying_price];
        int a = INT_MIN, b = INT_MIN, c = INT_MIN, d= INT_MIN;
       if(!bought)
       {
           
         buying_price = prices[i];
         bought = true;
         a =  profitMaximisation(prices,i+1,bought,buying_price,dp);
         buying_price = 0;
         bought = false;
         d = profitMaximisation(prices,i+1,bought,buying_price,dp);
       }
    
    else
    {   bought = false;
        b = prices[i]-buying_price + profitMaximisation(prices,i+2,bought,buying_price,dp);
        bought = true;
        c = profitMaximisation(prices,i+1,bought,buying_price,dp);
        
    }
       
       
       
       return dp[i][bought][buying_price] = max(max(max(a,b),c),d);
       
   }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(1002,-1)));
        return profitMaximisation(prices,0,false,0,dp);
    }
};