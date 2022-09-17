class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size();
        int n = colCosts.size();
        int ans = 0;
        int f = 0;
        int start_row = startPos[0], start_col = startPos[1], end_row = homePos[0], end_col = homePos[1];
        
        if(end_col < start_col){
            swap(start_row, end_row);
            swap(start_col,end_col);
            f = 1;
        }
          
        if(end_row < start_row){
            int diff = abs(start_row - end_row);
            int f1 = 0;
            
            for(int i = start_row-1; i>=end_row; i--){
                ans += rowCosts[i];
                f1 = 1;
            }
            int flag = 0;
            for(int i = start_col+1; i<= end_col; i++){
                ans += colCosts[i];
                flag = 1;
            }
            
            if(flag && f){
                ans -= colCosts[end_col];
                ans += colCosts[start_col];
            }
            
            if(f && f1){
                ans += rowCosts[start_row];
                ans -= rowCosts[end_row];
            }
               
            return ans;
            
        }
        else{
            int diff = abs(end_row - start_row);   
            int flag = 0;
            int f1 = 0;
            
            for(int i = start_row+1; i<= end_row; i++){
                ans += rowCosts[i];
                f1 = 1;
            }
            
            for(int i = start_col+1; i<=end_col; i++){
                ans += colCosts[i];
                flag = 1;
            }
            
            if(flag && f){
                ans -= colCosts[end_col];
                ans += colCosts[start_col];
            }
            
            if(f && f1){
                ans += rowCosts[start_row];
                ans -= rowCosts[end_row];
            }
            
            return ans;
        }
        
        
    }
};