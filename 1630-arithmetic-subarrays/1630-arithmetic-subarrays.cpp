class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m,false);
        
        for(int i = 0; i<m; i++){
            
            int start = l[i];
            int end = r[i];
           
            int flag = 0;
            int maxi = INT_MIN;
            int mini = INT_MAX;
            
            unordered_map <int,int> mp;
            
            for(int j = start; j<=end; j++){
                mp[nums[j]]++;
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
            }
            
            int interval = (maxi-mini)/(end-start);
            
            if((maxi - mini) %(end-start) != 0){
                continue;
            }
            
            
            for(int j = 0; j<=(end-start); j++){
                if(mp.find(mini + interval*j) == mp.end()){
                    flag = 1;
                    break;
                }
            }
            
            if(!flag)
                ans[i] = true;
        }
        
        return ans;
    }
};