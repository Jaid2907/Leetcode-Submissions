class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        
        while(i<n && nums[i] != 0)
            i++;
        
        while(j<n && i<n)
        {
            
            if(nums[j] != 0)
            {
                if(i<j)
                swap(nums[i],nums[j]);
                
                while( i<n && nums[i] != 0)
                    i++;
            }
         
            j++;
            
        }
    }
};