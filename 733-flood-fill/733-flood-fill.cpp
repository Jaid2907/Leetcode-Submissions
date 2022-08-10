class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        vector<int> row = {1,-1,0,0};
        vector<int> col = {0,0,1,-1};
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            
            for(int i = 0; i<4; i++){
                int r = x + row[i];
                int c = y + col[i];
                
                if(r<m && c<n && r>=0 && c>=0 && image[r][c] == image[x][y] && !visited[r][c]){
                    visited[r][c] = 1;
                    q.push({r,c});
                }
            }
            image[x][y] = color;
                
        }
        
        return image;
    }
};