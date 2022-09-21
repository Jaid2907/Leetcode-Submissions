class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int curr_sum = 0;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            
            if(!(nums[i] & 1)){
                curr_sum += nums[i];
            }
        }
        
        vector<int> ans;
        
        for(int i= 0; i<queries.size(); i++){
            int ind = queries[i][1];
            int val = queries[i][0];
            
            int prev_val = nums[ind];
            
            if(prev_val%2 == 0)
            curr_sum -= prev_val;
            
            nums[ind] += val;
            
            if(abs(nums[ind])%2 == 0){
                curr_sum += nums[ind];
            }
            
            ans.push_back(curr_sum);
        }
        
        return ans;
    }
};