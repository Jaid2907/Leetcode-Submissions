class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        
        int i = 0;
        int j = 0;
        
        while(i<n){
            
            while(true){
                ans += i-j+1;
                if(i+1 < n && nums[i] - nums[i+1]  == 1){
                    i++;
                }
                else{
                    i++;
                    j = i;
                    break;
                }
                
            }
        
        }
        
        return ans;
    }
};