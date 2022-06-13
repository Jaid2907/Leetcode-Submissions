class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        vector<int> ans(n,0);
        int k = 0;
        sort(nums.begin(), nums.end());
        while(i<j){
            ans[k++] = nums[i++];
            ans[k++] = nums[j--];
        }
        
        if(n&1)
        ans[k] = nums[i];
        
        return ans;
    }
};