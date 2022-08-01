vector<int> row = {0,0,1,-1};
vector<int> col = {1,-1,0,0};

class Solution {
public:
    int dfs(int i,int j,int m, int n,vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        
//         if(visited[i][j]){
//             return 0;
//         }
        // visited[i][j] = 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        for(int k = 0; k<4; k++){
            
                int x = i + row[k];
                int y = j + col[k];
                
                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]>grid[i][j]){
                    ans = max(ans, 1 + dfs(x,y,m,n,grid,dp));
            }
        }
        
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                // vector<vector<int>> visited(m, vector<int>(n,0));
                ans = max (ans, dfs(i,j,m,n,grid,dp));
            }
        }
        
        return ans+1;
    }
};