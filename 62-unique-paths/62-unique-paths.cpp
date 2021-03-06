class Solution {
public:
    int uniquePaths(int m, int n) {
     
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = 1;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                
                if(i == 0 && j == 0)
                    continue;
                int a = 0, b = 0;
                if(j>0)
                    a = dp[i][j-1];
                
                if(i>0)
                    b =  dp[i-1][j];
                
                dp[i][j] = a + b;
            }
        }
        
  
        return dp[m-1][n-1];
    }
};