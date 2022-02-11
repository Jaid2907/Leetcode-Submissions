class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int smallest_missing = 1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]>smallest_missing)
                continue;
            if(nums[i] == smallest_missing)
                smallest_missing++;
            
        }
        
        return smallest_missing;
    }
};