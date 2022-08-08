class Solution {
public:
    int helper (int i, int j, int end_x, int end_y,int m, int n, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<vector<int>>& dp, int& empty){
        if(i == end_x && j == end_y){
            return empty == 0;
        }
            
        visited[i][j] = 1;
        empty--;
        // if(dp[i][j] != -1)
        //     return dp[i][j];
        int a = 0, b = 0, c = 0, d = 0;
        
        if(i+1<m && grid[i+1][j] != -1 && !visited[i+1][j]){
            a = helper(i+1,j,end_x,end_y,m,n,grid,visited,dp,empty);
        }
        if(i-1>=0 && grid[i-1][j] != -1 && !visited[i-1][j]){
            b = helper(i-1,j,end_x, end_y, m,n, grid, visited,dp,empty);
        }
        if(j+1<n && grid[i][j+1] != -1 && !visited[i][j+1]){
            c = helper(i,j+1,end_x,end_y,m,n,grid,visited,dp,empty);
        }
        if(j-1>=0 && grid[i][j-1] != -1 && !visited[i][j-1]){
            d = helper(i,j-1,end_x, end_y, m, n, grid, visited,dp,empty);
        }
        visited[i][j] = 0;
        empty++;
        return dp[i][j] = a+b+c+d;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int start_x, start_y, end_x, end_y;
        int m = grid.size();
        int n = grid[0].size();
        int empty = 1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                if(grid[i][j] == 2){
                    end_x = i;
                    end_y = j;
                }
                if(grid[i][j] == 0)
                    empty++;
            }
        }
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return helper(start_x, start_y, end_x, end_y, m, n, grid, visited, dp,empty);
        
        
    }
};