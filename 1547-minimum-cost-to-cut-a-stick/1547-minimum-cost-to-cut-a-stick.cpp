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
        
        vector<vector<int>> dp(c+2, vector<int>(c+2,0));
        
        sort(cuts.begin(), cuts.end());
        
        for(int i = c; i>=1; i--){
            
            for(int j=1; j<=c; j++){
                
                if(i>j)
                    continue;
                
                dp[i][j] = INT_MAX;
                
                for(int k=i; k<=j; k++)
                    dp[i][j] = min (dp[i][j], dp[i][k-1] + dp[k+1][j] + cuts[j+1]-cuts[i-1]);
            }
        }
        
        return dp[1][c];
    }
};