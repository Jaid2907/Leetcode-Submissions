class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //Use of Sliding Window approach
        
        int n = nums.size();
        double sum = 0;
        double  avg = -1e7;
        
        for(int i=0; i<k; i++)
        {
            sum += nums[i];
        }
        
        avg = max(avg,sum/k);
        
        for(int i=k; i<n; i++)
        {
            sum += nums[i];
            sum -= nums[i-k];
          
            avg = max(avg,sum/k);
            
        }
        
        return avg;
    }
};