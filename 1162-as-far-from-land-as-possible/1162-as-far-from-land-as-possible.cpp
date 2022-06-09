class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        int ans = 0;
        
        int dist = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        
        if(q.size() == m*n)
            return -1;
        
        while(!q.empty()){
            int size = q.size();
            dist++;
            
            while(size--){
                auto [i,j] = q.front();
                q.pop();
                
                for(int k=0; k<4; k++){
                    int r = i + row[k];
                    int c = j + col[k];
                    
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c] == 0){
                        grid[r][c] = 1;
                        q.push({r,c});
                    }
                }
                    
            }
        }
        
        return dist-1;
        
    
        
        
    }
};