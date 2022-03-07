class Solution {
public:

    vector<int> minSubsequence(vector<int>& nums) {
        
      sort(nums.begin(),nums.end(),greater<int>());
      int total_sum = accumulate(nums.begin(),nums.end(),0);
      int n = nums.size();
        vector<int> ans;
        int subSum = 0;
        int i = 0;
        while( i<n && subSum<=total_sum)
        {
            subSum += nums[i];
            total_sum -= nums[i];
            ans.push_back(nums[i++]);
            
        }
    
        return ans;
        
    }
};