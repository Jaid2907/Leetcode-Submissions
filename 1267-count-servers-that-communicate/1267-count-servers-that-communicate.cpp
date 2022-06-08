class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        unordered_map<int, int> mp1, mp2;
        int cnt1 = 0, cnt2 = 0;
        
        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    cnt1++;
                
            }
            mp1[i] = cnt1;
            cnt1 = 0;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[j][i] == 1){
                    cnt2++;
                }
            }
            mp2[i] = cnt2;
            cnt2 = 0;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == 1)
                {
                    if(mp1[i]-1 >0 || mp2[j]-1>0)
                    ans ++;
                }
            }
        }
        
        return ans;
    }
};