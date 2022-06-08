class Solution {
public:
    bool helper(int row_lower, int row_upper, int col_lower, int col_upper, char choice, vector<vector<char>>& board){
        for(int i = row_lower; i<=row_upper; i++){
            for(int j=col_lower; j<=col_upper; j++){
                if(choice == board[i][j])
                    return false;
            }
        }
        
        return true;
    }
    bool isValidChoice(int i, int j, vector<vector<char>>& board, char choice){
        
        for(int row =0; row<9; row++){
            
            if(choice == board[row][j])
                return false;
            if(choice == board[i][row])
                return false;
        }
        
        if(i>=0 && i<=2){
            if(j>=0 && j<=2){
                return helper(0,2,0,2,choice,board);
            }
            else if(j>=3 && j<=5){
                return helper(0,2,3,5,choice,board);
            }
            else
                return helper(0,2,6,8,choice,board);
        }
        else if(i>=3 && i<=5){
            
            if(j>=0 && j<=2)
                return helper(3,5,0,2,choice,board);
            else if(j>=3 && j<=5)
                return helper(3,5,3,5,choice,board);
                else
                    return helper(3,5,6,8,choice,board);
        }
        else
        {
            if(j>=0 && j<=2)
                return helper(6,8,0,2,choice,board);
            else if(j>=3&& j<=5)
                return helper(6,8,3,5,choice,board);
            else
                return helper(6,8,6,8,choice,board);
        }
            
        return true;
        
        
    }
    void solver (int i, int j, vector<vector<char>>& board, vector<vector<int>>& empty, int k, vector<vector<char>>& ans){
        
        // if(k >= empty.size()){
        //     ans = board;
        //     return ;
        // }
        
        for(char choice = '1'; choice <='9'; choice++){
            if(isValidChoice(i, j, board,choice)){
                k++;
                board[i][j] = choice;
                if(k<empty.size())
                    solver(empty[k][0], empty[k][1], board, empty, k,ans);
                else
                    ans = board;
                board[i][j] = '.';
                k--;
            }
                
        }
        
        
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> empty;
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '.')
                    empty.push_back({i,j});
            }
        }
        int k=0;
        
        solver(empty[k][0],empty[k][1], board, empty, k,ans);
        
        board = ans;
    }
};