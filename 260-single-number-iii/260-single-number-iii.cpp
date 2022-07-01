class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       //Bit manpulation solution
        
        vector<int> ans = {0,0};
        unsigned int xor_res = 0;
        for(auto it: nums){
            xor_res ^= it;
        }
        
        unsigned int set_bit = xor_res & -(xor_res);
        
        for(auto it: nums){
            
            if((it & set_bit) == 0){
                ans[0] ^= it;
            }
            else
                ans[1] ^= it;
        }
        
        return ans;
    }
};