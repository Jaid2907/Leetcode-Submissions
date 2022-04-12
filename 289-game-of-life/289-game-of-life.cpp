class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> dup_board = board;
        
        int m = board.size();
        int n = board[0].size();
        int live_count = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                live_count = 0;
                    if(i>0 && dup_board[i-1][j] == 1)
                     live_count++;
                    if(j>0 && dup_board[i][j-1] == 1)
                        live_count++;
                    if(i+1<m && dup_board[i+1][j] == 1)
                        live_count++;
                    if(j+1<n && dup_board[i][j+1] == 1)
                        live_count++;
                    if(i>0 && j>0 && dup_board[i-1][j-1] == 1)
                        live_count++;
                    if(i+1<m && j+1<n && dup_board[i+1][j+1] == 1)
                        live_count++;
                    if(i+1<m && j>0 && dup_board[i+1][j-1] == 1)
                        live_count++;
                    if(i>0 && j+1<n && dup_board[i-1][j+1] == 1)
                        live_count++;
                
                if(dup_board[i][j] == 0)
                {
                    if(live_count == 3)
                        board[i][j] = 1;
                        
                }
                else
                {
                    if(live_count<2)
                        board[i][j] = 0;
                    else if(live_count ==2 || live_count == 3)
                        board[i][j] = 1;
                    else if(live_count>3)
                        board[i][j] = 0;
                    
                    
                }
            }
        }
    }
};