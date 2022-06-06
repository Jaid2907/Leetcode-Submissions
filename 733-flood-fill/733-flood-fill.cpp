class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int color = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        image[sr][sc] = newColor;
        
       
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int i = 0; i<4; i++){
                int r = node.first + row[i];
                int c= node.second + col[i];
                
                if(r<m && r>=0 && c<n && c>=0){
                    if(!visited[r][c]){
                        if(image[r][c] == color){
                            image[r][c] = newColor;
                            q.push({r,c});
                            visited[r][c] = 1;
                        }
                    }
                }
                
                
            }
        }
        
        return image;
    }
};