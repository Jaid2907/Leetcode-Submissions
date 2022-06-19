class Solution {
public:
    void paint (int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        
        visited[i][j] = 1;
        grid[i][j] = 2;
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        
        for(int k=0; k<4; k++){
            int r = i + row[k];
            int c = j + col[k];
            
            if(r>=0 && r<m && c>=0 && c<n && !visited[r][c] && grid[r][c] == 1){
                paint(r,c,grid,visited,m,n);
            }
        }
        
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int flag = 0;
        int start_i, start_j;
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(!visited[i][j] && grid[i][j] == 1){
                    start_i = i;
                    start_j = j;
                    paint(i,j,grid,visited,m,n);
                    flag = 1;
                    break;
                }
            }
            
            if(flag)
                break;
        }
        
        int ans = INT_MAX;
        fill(visited.begin(), visited.end(), vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({start_i,start_j});
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int k = 0; k<4; k++){
                int r = node.first + row[k];
                int c = node.second + col[k];
                
                if(r>=0 && r<m && c>=0 && c<n){
                    
                    if(grid[r][c] == 2 && !visited[r][c]){
                        visited[r][c] = 1;
                        q.push({r,c});
                    }
                    else if(grid[r][c] == 0){
                        grid[r][c] = grid[node.first][node.second]+1;
                        q.push({r,c});
                       
                    }
                    else if(grid[r][c] == 1){
                        visited[r][c] = 0;
                        ans = min(ans,grid[node.first][node.second]-2);
                    }
                    else{
                        if(grid[node.first][node.second]+1 < grid[r][c]){
                            grid[r][c] = grid[node.first][node.second]+1;
                            q.push({r,c});
                        }
                    }
                    
                }
            }
            
        }
        
//                 for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 cout<<grid[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        return ans;
        
        
    }
};