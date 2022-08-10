class Solution {
public:
    int bfs (int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited,int m, int n){
        vector<int> row = {1,-1,0,0};
        vector<int> col = {0,0,1,-1};
        queue<pair<int,int>> q;   
        q.push({i,j});
        int ans = 1;
        visited[i][j] = 1;
        
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            
            for(int i = 0; i<4; i++){
                int r = x + row[i];
                int c = y + col[i];
                
                if(r<m && c<n && r>=0 && c>=0 && !visited[r][c] && grid[r][c]){
                    ans++;
                    visited[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
        
        return ans;
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j]){
                    ans = max(ans, bfs(i,j,grid,visited,m,n));
                }
            }
        }
        
        return ans;
        
        
    }
};