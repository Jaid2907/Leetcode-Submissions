class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long int ans = 0;
        int n = nums.size();
        int i = 0;
        
        while(i<n){
         
            if(nums[i] != 0){
                i++;
                continue;
            }
                
            int cnt = 1;
            
            while(i<n && nums[i] == 0){
                ans += cnt;
                cnt++;
                i++;
            }
        }
        
        return ans;
    }
};