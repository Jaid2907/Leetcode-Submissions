int row[4] = {0,0,1,-1};
int col[4] = {1,-1,0,0};
int mod = 1e9+7;

class Solution {
public:
    int dfs (int i, int j, int m , int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
         int cnt = 0;
        
        for(int k = 0; k<4; k++){
            int x = i + row[k];
            int y = j + col[k];
            
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]>grid[i][j]){
                cnt = (cnt%mod +  dfs(x,y,m,n,grid,dp)%mod)%mod;
            }
        
            
        }
        
        return dp[i][j] = (1 + cnt%mod)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
     
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans = (ans%mod +  dfs(i,j,m,n,grid,dp)%mod)%mod;
            }
        }
        
        return ans;
    }
};