class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> mp;
        int sum = 0, cnt = 0;
        mp[0] = -1;
        int pre = 0, mod = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            sum %= k;
            if(mp.find(sum)!= mp.end() && abs(mp[sum]-i)>1)
                return true;
            if(mp.find(sum) == mp.end())
            mp[sum] = i;
            if(i>0 && nums[i] == 0 && nums[i-1] == 0)
                return true;
            
        }
        
        return false;
    }
};