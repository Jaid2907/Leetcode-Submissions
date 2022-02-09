class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int> mp;
       
        for(auto& it: nums)
            mp[it]++;
        
        for(auto& it: mp)
        {
            if((!k && it.second>1) || (k && mp.find(it.first+k)!=mp.end()))
                cnt++;
        }
        
        return cnt;
        
    }
};