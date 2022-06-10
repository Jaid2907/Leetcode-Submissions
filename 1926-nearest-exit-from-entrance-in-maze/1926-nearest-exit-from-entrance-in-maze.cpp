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
        q.push({a,b});
        maze[a][b] = '+';
        int dist = 0;
    
        
       
        while(!q.empty()){
            
            int size = q.size();
            if(size)
                dist++;
            
            while(size--){
                
            auto [i,j] = q.front();
            q.pop();
            
            for(int k=0; k<4; k++){
                int r = i + row[k];
                int c = j + col[k];
                
                if(r>=0 && r<m && c>=0 && c<n && maze[r][c] == '.'){
                    
                    q.push({r,c});
                    maze[r][c] = '+';
                    
                    if(r==0 || r==m-1 || c==0 || c==n-1)
                        return dist;
                }
            }    
        }
            
        }
        

        
        return -1;
    }
};