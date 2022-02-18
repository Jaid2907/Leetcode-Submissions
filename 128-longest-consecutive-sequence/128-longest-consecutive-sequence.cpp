class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        multiset<int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
            mp.insert(nums[i]);
        
        int longest = 0;
        int flag = 0;
        int prev;
        int ans = INT_MIN;
        
        for(auto it: mp)
        {
            if(flag == 0)
            {
                prev = it;
                longest++;
                flag = 1;
                continue;
                
            }
            if(it-prev == 0)
            {
                prev = it;
                continue;
            }
            if(it - prev == 1)
            {
                longest++;
            }
            else
            {
                ans = max(ans,longest);
                longest = 1;
                
            }
            prev = it;
            
        }
        ans = max(longest,ans);
        return ans;
    }
};