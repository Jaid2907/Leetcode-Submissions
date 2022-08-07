class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int ans = 0;
        unordered_map<int,int> mp;
        int j = 0;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
            
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            
            if(mp.size()<=k)
              ans += (i-j+1);
        }
        
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(nums,k) - atMost(nums,k-1);
    }
};