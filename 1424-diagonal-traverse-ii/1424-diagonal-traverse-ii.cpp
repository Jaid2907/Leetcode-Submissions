class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int max_col = 0;
        int m = nums.size();
        
        for(int i = 0; i<m; i++){
            if(max_col < nums[i].size()){
                max_col = nums[i].size();
            }
           
        }
        
        unordered_map <string, int> mp;
        queue<pair<int,int>> q;
        vector<int> ans;
        q.push({0,0});
        string key = to_string(0) + "*" + to_string(0);
        mp[key] = 1;
        
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--){
                auto node = q.front();
                q.pop();
                
                
                
                ans.push_back(nums[node.first][node.second]);
                key = to_string(node.first + 1 ) + "*" + to_string(node.second);
                if(node.first + 1 < m && node.second < nums[node.first + 1].size() && !mp[key]){
                    q.push({node.first + 1, node.second});
                    mp[key] = 1;
                }
                
                key = to_string(node.first) + "*" + to_string(node.second + 1);
                if(node.second + 1 <nums[node.first].size() && !mp[key]){
                    q.push({node.first, node.second + 1});
                    mp[key] = 1;
                }
            }
        }
        
        return ans;
    }
};