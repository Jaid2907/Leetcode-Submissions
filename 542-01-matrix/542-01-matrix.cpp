class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m == 0)
            return mat;
        int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX-1e5));
        
        //First pass top to bottom for up and left
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                else
                {
                    if(i>0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                    
                    if(j>0)
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        
        //Second pass from bottom to up for down and right side
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                
                if(mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if(i+1<m)
                    dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    
                    if(j+1<n)
                    dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                }
            }
        }
        
        return dp;
    }
};