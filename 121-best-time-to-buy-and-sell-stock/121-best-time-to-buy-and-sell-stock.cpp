class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int n = prices.size();
        
        for(int i=0; i<n; i++)
        {
            if(prices[i]<minimum)
                minimum = prices[i];
            prices[i] -= minimum;
        }
        
        return *max_element(prices.begin(),prices.end());
        
    }
};