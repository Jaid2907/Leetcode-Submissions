class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n);
        
        vector<long long int> prefix_sum(n);
        
        long long int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            prefix_sum[i] = sum;
        }
        
        for(int i=0; i<n; i++)
        {
            if(i-k<0 || i+k>=n)
            {
                ans[i] = -1;
                continue;
            }
            
            ans[i] = (prefix_sum[i+k]-prefix_sum[i-k]+nums[i-k])/(2*k+1);
        }
        return ans;
    
    }
};