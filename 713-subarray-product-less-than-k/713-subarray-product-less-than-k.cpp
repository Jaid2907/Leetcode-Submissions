class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int j = 0;
        long long int prod = 1;
        
        for(int i = 0; i<n; i++){
            
            prod *= nums[i];
            
           
            
            if(prod >= k){
                
                
                while(j<=i && prod>=k){
                    prod /= nums[j];
                    j++;
                }
            }
             if(prod<k)
                ans += i-j+1;
        }
        
        return ans;
    }
};