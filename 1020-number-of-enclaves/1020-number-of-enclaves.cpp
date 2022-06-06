class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        
        int m = grid.size();
        int n = grid[0].size();
        if(i == 0 || i == m-1 || j == 0 || j == n-1)
            return 0;
        
       
        
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        int flag = 0;
        int cnt = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            cnt++;
            
            for(int i=0; i<4; i++){
                int r = node.first + row[i];
                int c = node.second + col[i];
                
                if(r>=0 && r<m && c>=0 && c<n){
                    
                    if(grid[r][c] == 1){
                        if(r==0 || r==m-1 || c==0 || c==n-1)
                            flag = 1;
                    }
                    
                    if(!visited[r][c]){
                       
                        if(grid[r][c] == 1){
                                visited[r][c] = 1;
                                q.push({r,c});
                            }
                            
                        }
                          
                    }
                    
                }
            }
        
        if(flag == 1)
            return 0;
        return cnt;
        }
        
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    cnt += bfs(i,j,visited,grid);
                }
            }
        }
        
        return cnt;
        
    }
};