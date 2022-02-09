class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        unordered_map <int,int> mp;
        int n = nums.size();
        int cnt = 0;
        
        for(int i=0; i<n; i++)
        {
            if(mp.find(k+nums[i]) != mp.end())
            {
               
               
                cnt  += mp[k+nums[i]];
            }
             if( mp.find(nums[i]-k)!=mp.end())
            {
                cnt += mp[nums[i]-k];
            }
            
             mp[nums[i]]++;
           
        }
        
        return cnt;
    }
};