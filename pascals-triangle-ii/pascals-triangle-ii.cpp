class Solution {
public:
    int pascal(int i, int j, vector<vector<int>>& dp)
    {
        if(j == 0 || j == i)
            return dp[i][j] = 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = pascal(i-1,j,dp) + pascal(i-1,j-1,dp);
        
    }
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1,1);
        vector<vector<int>> dp(rowIndex+1,vector<int>(rowIndex+1,-1));
        for(int i =0; i<rowIndex+1; i++)
            v[i] = pascal(rowIndex,i,dp);
        
        return v;
        
        
        
    }
};