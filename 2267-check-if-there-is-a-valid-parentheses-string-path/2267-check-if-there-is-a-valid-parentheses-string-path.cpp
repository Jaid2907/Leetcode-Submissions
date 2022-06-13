class Solution {
public:
    
    bool path (int k, int i, int j, vector<vector<char>>& grid, int m, int n,vector<vector<vector<int>>>& dp){
        
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        
        
           
        if(grid[i][j] == '(')
            k++;
        else
            k--;
        
        if(k<0)
            return false;
        if(i==m-1 && j == n-1){
            return (k==0);
        }
        
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        
        
        
        bool a = path(k,i+1,j,grid,m,n,dp);
        bool b = path(k,i,j+1,grid,m,n,dp);
        
        
       
      
        return dp[i][j][k] = a||b;
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp (m+1, vector<vector<int>>(n+1,vector<int>(200,-1)));
        int k = 0;
        
        return path(k,0,0,grid,m,n,dp);
        
    }
};