int mod = 1e9+7;
class Solution {
public:
    
    int helper (int i, int j, int m, int n, int maxMove, vector<vector<vector<int>>>& dp){
        
        if(i<0 || i>=m || j<0 || j>=n)
            return 1;
        if(maxMove<=0)
            return 0;
        
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        int ans = 0;
        for(int k = 0; k<4; k++){
            
            ans = (ans + helper(i+dx[k],j + dy[k],m,n,maxMove-1,dp))%mod;
        }
        
        return dp[i][j][maxMove] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp (m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        
        return helper(startRow, startColumn,m,n,maxMove,dp);
    }
};