class Solution {
public:
    bool bfs(int i, int j, vector<vector<int>>& visited, int m, int n, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        int flag = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            
            for(int i =0; i<4; i++){
                int r = x + row[i];
                int c = y + col[i];
                
                if(r<m && c<n && r>=0 && c>=0 && grid[r][c] == 0){
                    
                    if(r == m-1 || r == 0 || c == n-1 || c == 0){
                        flag = 1;
                    }
                        
                       
                    if(!visited[r][c]){
                        q.push({r,c});
                        visited[r][c] = 1;
                    }
              
                }
            }
        }
        if(flag)
            return false;
        return true;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> visited(m, vector<int>(n,0));
    
        
        for(int i = 1; i<m-1; i++){
            for(int j = 1; j<n-1; j++){
                
                if(!visited[i][j] && grid[i][j] == 0){
                    if(bfs(i,j,visited,m,n,grid)){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};