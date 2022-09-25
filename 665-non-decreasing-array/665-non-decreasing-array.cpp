class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return true;
        
        int f = 0;
        
        for(int i = 1; i<n; i++){
            
            if(nums[i] >= nums[i-1])
                continue;
            
            if(f == 0){
                f = 1;
                    if((i-2>=0)&&nums[i-2] <= nums[i] || i==1){
                    nums[i-1] = nums[i];
                    }
                else{
                    nums[i] = nums[i-1];
                }
            }
            else
                return false;
            
        }
        
        return true;
    }
};