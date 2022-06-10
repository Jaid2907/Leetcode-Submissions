class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited,vector<vector<int>>& ans){
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},0});
        ans[i][j] = 0;
        visited[i][j] = 1;
        
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        
        int m = grid.size();
        int n = grid[0].size();
        
        while(!q.empty()){
            
            auto  node = q.front();
            q.pop();
            
            for(int k=0; k<4; k++){
                
                int r = node.first.first + row[k];
                int c = node.first.second + col[k];
                
                if(r>=0 && r<m && c<n && c>=0){
                    if(!visited[r][c] && grid[r][c] == 1){
                        visited[r][c] = 1;
                        ans[r][c] = min(ans[r][c],node.second+1);
                        q.push({{r,c},node.second+1});
                        
                    }
                }
            }
               
        }
        
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,1e5));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    vector<vector<int>> visited(m, vector<int>(n,0));
                     bfs(i,j,grid,visited,ans);
                }
            }
        }
        
        int time = 0;
     
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ans[i][j] == 1e5 && grid[i][j]!=0)
                    return -1;
                else if(ans[i][j] != 1e5){
                    time = max(time,ans[i][j]);
                }
            }
        }
        
        return time;
    }
};