class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>= grid.size() || j>=grid[0].size())
            return 0;
        if(visited[i][j] == 1)
            return 0;
        
        visited[i][j] = 1;
        
        if(grid[i][j] == 0)
            return 0;
        
        int a = helper(i-1,j,visited,grid);
        int b = helper(i+1,j,visited,grid);
        int c = helper(i,j-1,visited,grid);
        int d = helper(i,j+1,visited,grid);
        
        
        return a+b+c+d+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    
                    ans = max(ans,helper(i,j,visited,grid));
                }
            }
        }
        
        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};