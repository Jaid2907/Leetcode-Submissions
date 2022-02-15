class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int xor_value = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            xor_value^=nums[i];
        }
        
        return xor_value;
    }
};