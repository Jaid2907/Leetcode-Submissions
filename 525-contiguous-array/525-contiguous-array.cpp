class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int max_length = 0;
        
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
                sum--;
            else
                sum++;
            if(sum == 0)
                max_length = max(max_length,i+1);
           if(mp.find(sum) == mp.end())
               mp[sum] = i;
            else
            {
                max_length = max(max_length, i-mp[sum]);
            }
        }
        
        return max_length;
    }
};