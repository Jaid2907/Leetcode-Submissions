class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map <int,int> mp;
        int n = nums.size();
        
        int ans = 0;
        mp[0]++;
        for(int i=0; i<n; i++)
        {
            if(nums[i]& 1)
                cnt++;
            
            if(mp.find(cnt-k) != mp.end())
            {
                ans += mp[cnt-k];
            }
            
            mp[cnt]++;
            
            
        }
        
        return ans;
        
    }
};