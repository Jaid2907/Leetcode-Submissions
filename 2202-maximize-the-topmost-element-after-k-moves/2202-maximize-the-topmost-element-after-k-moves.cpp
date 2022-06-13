class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0)
            return nums[0];
        if(k&1 && n == 1)
            return -1;
        if(k == 1)
            return nums[1];
        if(k>n)
            return *max_element(nums.begin(),nums.end());
            
        int a =  *max_element(nums.begin(), nums.begin()+k-1);
        if(a<nums[k])
            return nums[k];
        else
            return a;
    }
};