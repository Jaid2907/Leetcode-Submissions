class Solution {
public:
    long long int nCr (long long int n, long long int r,vector<vector<int>>& dp){
        
        if(r>n)
            return 0;
        if(r == 0 || r == n)
            return 1;
        if(dp[n][r] != -1)
            return dp[n][r];
        return nCr(n-1,r,dp) + nCr(n-1,r-1,dp);
    }
    int numTrees(int n) {
     
        //Catlan number 
        // 2nCn / (n+1)
        vector<vector<long long int>> dp (2*n+1, vector<long long int> (2*n+1,-1));
        
        for(int i=1; i<2*n+1; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=2*n; i++){
            for(int j=1; j<=2*n; j++){
                
                if(i==j){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }
        
        return dp[2*n][n]/(n+1);
        
       
        
    }
};