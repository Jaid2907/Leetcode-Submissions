class Solution {
public:
    void dfs (int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid, int m, int n){
        
        visited[i][j] = 1;
        
        if( i+1 < m && !visited[i+1][j] && grid[i+1][j] == '1')
            dfs(i+1,j,visited,grid,m,n);
        
        if(i-1>=0 && !visited[i-1][j] && grid[i-1][j] == '1')
            dfs(i-1,j,visited,grid,m,n);
        
        if(j+1<n && !visited[i][j+1] && grid[i][j+1] == '1')
            dfs(i,j+1,visited,grid,m,n);
        
        if(j-1>=0 && !visited[i][j-1] && grid[i][j-1] == '1')
            dfs(i,j-1,visited,grid,m,n);
    }
    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int r = node.first +  row[i];
                int c = node.second + col[i];
                
                if(r<m && r>=0 && c<n && c>=0){
                    if(!visited[r][c] && grid[r][c] == '1'){
                        visited[r][c] = 1;
                        q.push({r,c});
                    }
                }
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int cnt = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i,j,visited,grid,m,n);
                    cnt++;
                }
            }
        }
        
        
        return cnt;
    }
};