class Solution {
public:
    int helper (int i, int j, vector<int>& cuts,vector<vector<int>>& dp){
        
        if(i>j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
    
        int a = 1e7;
      
        for(int k=i; k<=j; k++){
            
            a = min (a, helper(i,k-1,cuts,dp) + helper(k+1,j,cuts,dp) + cuts[j+1]-cuts[i-1]);
        }
     
        return dp[i][j] =  a;
    }

    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        vector<vector<int>> dp(c+2, vector<int>(c+2,-1));
        sort(cuts.begin(), cuts.end());
        return helper(1,c,cuts,dp);
    }
};