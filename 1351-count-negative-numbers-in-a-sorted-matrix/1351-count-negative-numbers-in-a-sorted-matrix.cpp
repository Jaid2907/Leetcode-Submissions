class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
     
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
            
        for(int i = 0; i<m; i++){
            
            int low = 0, high = n-1;
            int last_pos = 0;
            
            while(low<=high){
                
                int mid = low + (high - low)/2;
                
                if(grid[i][mid] >= 0){
                    last_pos = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
           
            ans += n-low;
        }
        
        return ans;
    }
};