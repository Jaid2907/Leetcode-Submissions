class Solution {
public:
    int shortestPath (vector<vector<int>>& grid){
         
            int n = grid.size();
            queue<vector<int>> q;
            vector<vector<int>> visited(n, vector<int>(n,0));
        
            if(grid[0][0] == 1)
                return -1;
        
            q.push({0,0,1});
            visited[0][0] = 1;
        
            vector<int> row = {0,1,-1,0,+1,-1,+1,-1};
            vector<int> col = {1,0,0,-1,+1,-1,-1,+1};
            int cnt = 1;
            
        
            while (!q.empty()){
                auto node = q.front();
                q.pop();
                
               
                int curr_row = node[0];
                int curr_col = node[1];
                int dist = node[2];
                
                if( curr_row == n-1 && curr_col == n-1)
                    return dist;
                
                for(auto i: row){
                    for(auto j: col)
                        
                        if(curr_row + i >=0 && curr_row + i<n && curr_col +j>=0 && curr_col + j<n)
                        {
                            if(grid[curr_row+i][curr_col+j] == 0 && !visited[curr_row+i][curr_col+j]){
                                visited[curr_row+i][curr_col+j] = 1;
                                q.push({curr_row + i, curr_col + j, dist+1});
                                cnt++;
                                
                                 
                            }
                        }
                }
                
            }
        
        return -1;
            
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        return shortestPath(grid);
        
    }
};