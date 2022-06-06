class Solution {
public:
    bool bfs (int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        
        int m = grid2.size();
        int n = grid2[0].size();
        vector<pair<int,int>> temp;
        vector<int> row = {1,-1,0,0};
        vector<int> col = {0,0,1,-1};
        
        queue<pair<int,int>> q;
        q.push({i,j});
        temp.push_back({i,j});
        visited[i][j] = 1;

        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            for(int i=0; i<4; i++){
                int r = node.first + row[i];
                int c = node.second + col[i];
                
                if(r>=0 && r<m && c>=0 && c<n){
                    if(!visited[r][c]){
                        if(grid2[r][c] == 1){
                            visited[r][c] = 1;
                            q.push({r,c});
                            temp.push_back({r,c});
                        }
                        
                       
                    }
                }
            }
            
            
            
        }
        
        for(auto it: temp){
            
                if(grid1[it.first][it.second] == 0)
                    return false;
            }
        
        
        
        return true;
        
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
     
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int cnt = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(!visited[i][j] && grid2[i][j] == 1){
                    if(bfs(i,j,visited,grid1,grid2))
                    {
                        
                        cnt++;
                    }
                        
                }
            }
        }
        return cnt;
    }
};