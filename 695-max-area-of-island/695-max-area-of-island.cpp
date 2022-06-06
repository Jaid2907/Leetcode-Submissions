class Solution {
public:
    int bfs (int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 1;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int r = node.first + row[i];
                int c = node.second + col[i];
                
                if(r<m && r>=0 && c<n && c>=0){
                    if(!visited[r][c]){
                        if(grid[r][c]){
                            visited[r][c] = 1;
                            q.push({r,c});
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]){
                    ans = max(ans,bfs(i,j,visited,grid));
                }
            }
        }
        
        return ans;
        
    }
};