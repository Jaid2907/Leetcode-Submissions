class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        int cnt = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int i = 0; i<4; i++)
            {
                int r = node.first + row[i];
                int c = node.second + col[i];
                
                if(r<0 || r==m || c<0 || c==n){
                    cnt++;
                }
                else if(grid[r][c] == 0)
                {
                    visited[r][c] = 1;
                    cnt++;
                }
                else if(!visited[r][c])
                {
                    visited[r][c] = 1;
                    q.push({r,c});
                }
                    
                    
            }
            
            
        }
        
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    return  bfs(i,j,visited,grid);
                    
                }
            }
        }
        
        return 0;
        
        
        
    }
};