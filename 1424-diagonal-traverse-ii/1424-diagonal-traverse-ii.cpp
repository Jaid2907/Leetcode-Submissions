class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int r = nums.size();
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        
        for(int i = r-1; i>=0; i--){
            
            for(int j = 0; j<nums[i].size(); j++){
                mp[i + j].push_back(nums[i][j]);
            }
        }
        
        for(int i = 0; i<mp.size(); i++){
            for(auto &it: mp[i]){
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};