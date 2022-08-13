class Solution {
public:
     vector<int> row = {0,0,1,-1};
     vector<int> col = {1,-1,0,0};
    bool dfs (int i,int j,int k, vector<vector<char>>& board, string &word, int& m, int& n){
      
        if(k == word.size())
            return true;
        
        bool ans = false;
        char a = board[i][j];
        board[i][j] = '*';
        
        for(int l = 0; l<4; l++){
            int x = i + row[l];
            int y = j + col[l];
            
            if(x>=0 && y>=0 && x<m && y<n && word[k] == board[x][y]){
                ans = ans || dfs(x,y,k+1,board,word,m,n);
            }
        }
        board[i][j] = a;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ans = false;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == word[0])
                ans = ans || dfs(i,j,1,board,word,m,n);
                if(ans)
                    return ans;
            }
        }
        
        return false;
    }
};