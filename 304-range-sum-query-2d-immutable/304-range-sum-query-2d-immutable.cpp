class NumMatrix {
public:
    vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        prefix_sum.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = 0;
        
        for(int i=0; i<m; i++)
        {
            sum = 0;
            for(int j=0; j<n; j++)
            {
                sum += matrix[i][j];
                prefix_sum[i+1][j+1] = sum;
                
            }
        }
        
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = 0;
        
        for(int i = row1+1; i<=row2+1; i++)
        {
            ans += prefix_sum[i][col2+1] - prefix_sum[i][col1];
        }
        
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */