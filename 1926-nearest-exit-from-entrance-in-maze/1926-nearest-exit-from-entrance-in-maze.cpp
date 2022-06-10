class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size();
        int n = maze[0].size();
        int a = entrance[0];
        int b = entrance[1];
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m, vector<int>(n,INT_MAX - 1e5));
        

        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && maze[i][j] == '.'){
                    if(!(i == a && j == b)){
                        ans[i][j] = 0;
                        q.push({i,j});
                    }
                    
                }
            }
        }
        
       
        while(!q.empty()){
            
            auto [i,j] = q.front();
            q.pop();
            
            for(int k=0; k<4; k++){
                int r = i + row[k];
                int c = j + col[k];
                
                if(r>=0 && r<m && c>=0 && c<n && maze[r][c] != '+'){
                    
                    if(ans[i][j]+1<ans[r][c]){
                        ans[r][c] = ans[i][j] + 1;
                        q.push({r,c});
                    }
                }
            }
        }
        

        if(ans[a][b] == INT_MAX-1e5)
            return -1;
        return ans[a][b];
    }
};