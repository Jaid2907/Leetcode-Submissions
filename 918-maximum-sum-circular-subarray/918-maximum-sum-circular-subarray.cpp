class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum_of_arr = accumulate(nums.begin(), nums.end(), 0);
        
        //Kadane in non-circular array
        int max_sum = INT_MIN, max_till_now = 0,sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            max_sum = max(max_sum,sum);
            if(sum<0){
                sum = 0;
            }
        }
        
        //Kadane for circular part by inverting signs so that min subarray can be found
        int min_sum = INT_MIN;
        sum = 0;
        
        for(int i = 0; i<n; i++){
            sum += (-nums[i]);
            
            min_sum = max(min_sum, sum);
            if(sum<0)
                sum = 0;
        }
        
        if(sum_of_arr + min_sum == 0)
            return max_sum;
        return max(max_sum, sum_of_arr + min_sum);
    }
};