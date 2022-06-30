class Solution {
public:
    int maximumDifference(vector<int>& prices) {
        
        int n = prices.size();
        int mini = prices[0];
        int maxi = -1;
        
        
        for(int i=0; i<n; i++){
            
            if(prices[i]-mini>0)
                maxi = max (maxi, prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        
        return maxi;
    }
};