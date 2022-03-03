class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int mid = 1;
        int sum = 0;
        int ans = 0;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            sum = 0;
            
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]%mid == 0)
                    sum += nums[i]/mid;
                else
                    sum += nums[i]/mid + 1;
            }
            
            if(sum<=threshold)
            {
                high = mid-1;
                ans = mid;
            }
            else
            {
                low = mid+1;
            }
                
        }
        
        return ans;
    }
};