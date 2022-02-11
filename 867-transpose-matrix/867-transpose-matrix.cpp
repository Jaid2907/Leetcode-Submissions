class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat;
        vector<int> temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                temp.push_back(matrix[j][i]);
            }
            mat.push_back(temp);
            temp.clear();
        }
        
        return mat;
    }
};