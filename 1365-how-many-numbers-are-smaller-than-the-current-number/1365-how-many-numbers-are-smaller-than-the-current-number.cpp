class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int mp[101] = {0};
        int freq[101] = {0};
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }
        
        for(int i = 1; i<=100; i++){
            mp[i] = freq[i-1] + mp[i-1];
        }
        
        vector<int>ans(n,0);
        
        for(int i =0; i<n; i++){
            ans[i] = mp[nums[i]];
        }
        
        return ans;
    }
};