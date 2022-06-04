class Solution {
public:
    bool isSafe (int row, int col, vector<string>& chessboard, int n){
        
        for(int i =0; i<n ;i++)
        {
            if(chessboard[row][i] == 'Q' || chessboard[i][col] == 'Q')
                return false;
        }
        int i = row+1;
        int j = col+1;
        
        while(i<n && j<n)
        {
            if(chessboard[i][j] == 'Q')
                return false;
            i++;
            j++;
        }
        i = row-1;
        j = col-1;
        
        while(i>=0 && j>=0){
            if(chessboard[i][j] == 'Q')
                return false;
            
            i--;
            j--;
        }
        
        i = row-1;
        j = col+1;
        
        while(i>=0 && j<n)
        {
            if(chessboard[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        
        i = row+1;
        j = col-1;
        
        while(i<n && j>=0)
        {
            if(chessboard[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        
        return true;
        
    }
    void nQueen(int n, int col, vector<string>& chessboard, vector<vector<string>>& ans){
        
        if(col >= n){
            ans.push_back(chessboard);
            return ;
            
        }
        
        for(int row=0; row<n; row++)
        {
            if(isSafe(row, col, chessboard, n)){
                chessboard[row][col] = 'Q';
                nQueen(n,col+1,chessboard,ans);
                chessboard[row][col] = '.';
            }
           
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<vector<string>> ans;
        vector<string> chessboard(n);
        string s(n,'.');
        
        for(int i=0; i<n; i++)
            chessboard[i] = s;
        nQueen(n,0,chessboard,ans);
        
        return ans;
        
        
        
        
    }
};