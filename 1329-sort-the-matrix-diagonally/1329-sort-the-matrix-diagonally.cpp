class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        unordered_map<int,vector<int>> mp;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                mp[j-i].push_back(mat[i][j]);
            }
        }
        
        for(auto &it: mp){
            sort(it.second.begin(), it.second.end());
        }
        
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                ans[i][j] = mp[j-i].back();
                mp[j-i].pop_back();
            }
        }
        
        return ans;
        
    }
};