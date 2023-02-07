class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        unordered_map<int,int> mp;
        int ans = 0;

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;

            while(j<i && mp.size() > 2){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            ans = max(ans, i-j+1);
        }

        return ans;
    }
};