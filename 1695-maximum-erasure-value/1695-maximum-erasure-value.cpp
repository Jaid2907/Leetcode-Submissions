class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int curr_sum = 0;
               
        curr_sum = 0;
        int ans = 0;
        int j = 0, i = 0;
        
        for( i=0; i<n; i++){
            
            if(mp.find(nums[i]) != mp.end()){
                ans = max(ans, curr_sum);
                
                while(j<n && j!= mp[nums[i]]){
                    curr_sum -= nums[j];
                    mp.erase(nums[j]);
                    j++;
                }
                j++;
                mp[nums[i]] = i;
                
            }
            else
            {
                mp[nums[i]] = i;
                curr_sum += nums[i];
                
            }
        }
        
        ans = max(ans, curr_sum);
        
        return ans;
    }
};