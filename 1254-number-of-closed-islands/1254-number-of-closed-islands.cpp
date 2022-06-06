class Solution {
public:
    bool bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        
        int m = grid.size();
        int n = grid[0].size();
        if(i == 0 || i == m-1 || j == 0 || j == n-1)
            return false;
        
       
        
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        int flag = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int r = node.first + row[i];
                int c = node.second + col[i];
                
                if(r>=0 && r<m && c>=0 && c<n){
                    
                    if(grid[r][c] == 0){
                        if(r==0 || r==m-1 || c==0 || c==n-1)
                            flag = 1;
                    }
                    
                    if(!visited[r][c]){
                       
                        if(grid[r][c] == 0){
                                visited[r][c] = 1;
                                q.push({r,c});
                            }
                            
                        }
                          
                    }
                    
                }
            }
        
        if(flag == 1)
            return false;
        return true;
        }
        
        
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 0){
                    if(bfs(i,j,visited,grid))
                    {
                       
                        cnt++;
                    }
                        
                }
            }
        }
        
        return cnt;
        
        
    }
};