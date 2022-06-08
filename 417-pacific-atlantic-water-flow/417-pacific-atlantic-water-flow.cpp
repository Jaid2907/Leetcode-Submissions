class Solution {
public:    
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<bool>>& marking){
        
        int m =  heights.size();
        int n =  heights[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            visited[node.first][node.second] = 1;
            marking[node.first][node.second] = true;

            
            for(int k=0; k<4; k++){
                int r = node.first + row[k];
                int c = node.second + col[k];
                
                if(r>=0 && r<m && c>=0 && c<n){
                    if(!visited[r][c]){
                        
                        if(heights[r][c] >= heights[node.first][node.second]){
                             marking[r][c] = true;
                             visited[r][c] = 1;
                             q.push({r,c});
                        }
                    }
                }
            }
            
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m =  heights.size();
        int n =  heights[0].size();
        
        vector<vector<int>> ans;
        queue<pair<int,int>> pacific, atlantic;
        
        for(int i=0; i<m; i++){
            pacific.push({i,0});
            atlantic.push({i,n-1});
        }
        for(int i=0; i<n; i++){
            pacific.push({0,i});
            atlantic.push({m-1,i});
        }
        
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        
        bfs(heights,pacific, pac);
        bfs(heights,atlantic,atl);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
             if(pac[i][j] && atl[i][j])
                 ans.push_back({i,j});
            }
        }
        
        return ans;
        
        
        
        
        
    }
};