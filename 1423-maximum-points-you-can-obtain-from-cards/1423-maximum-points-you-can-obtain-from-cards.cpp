class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX, curr = 0;
        k = n-k;
        
        for(int i =0; i<k; i++){
            curr += nums[i];
            
        }
        ans = min(curr, ans);
        for(int i = k; i<n; i++){
            curr += nums[i];
            curr -= nums[i-k];
            ans = min(curr, ans);
        }
        
        return s-ans;
        
        
    }
};