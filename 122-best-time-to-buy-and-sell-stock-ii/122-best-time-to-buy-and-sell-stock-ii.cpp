class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mini = prices[0];
        int maxi = INT_MIN;
        int profit = 0;
        
        
        for(int i=0; i<n; i++){
            
            if(prices[i] - mini > 0){
                profit += prices[i]-mini;
                mini = prices[i];
                continue;
            }
            
            mini = min (mini, prices[i]);
            
            
        }
        
        // if(prices[n-1]-mini>0)
        //     profit += prices[n-1]-mini;
        return profit;
    
    }
    
};