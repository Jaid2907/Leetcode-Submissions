class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        n *= 2;
        vector<int> ans(n,0);
        
        int i = 0, j = n/2;
        int k = 0;
        
        while(k<n){
            if(k&1)
                ans[k++] = nums[j++];
            else
                ans[k++] = nums[i++];
        }
        
        return ans;
    }
};