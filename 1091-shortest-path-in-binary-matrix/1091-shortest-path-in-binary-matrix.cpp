class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;
        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> row = {1,1,1,0,0,-1,-1,-1};
        vector<int> col = {-1,0,1,-1,1,1,0,-1};
        int cnt = 0;
        visited[0][0] = 1;
        while(!q.empty()){
            int size = q.size();
            cnt++;
            while(size--){
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                 if(x == m-1 && y == n-1)
                            return cnt;

            
                for(int i = 0; i<8; i++){
                    int r = x + row[i];
                    int c = y + col[i];
                    
                    if(r<m && c<n && r>=0 && c>=0 && grid[r][c] == 0 && !visited[r][c]){
                        visited[r][c] = 1;
                        q.push({r,c});
                        
                        
                    }
                
                }       
            }
            
            
        }
        return -1;
    }
};