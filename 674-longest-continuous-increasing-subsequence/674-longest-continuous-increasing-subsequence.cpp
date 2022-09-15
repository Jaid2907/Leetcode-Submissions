class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int i = 1;
        int cnt = 0;
        while(i<n){
            cnt = 0;
            int f = 0;
            while(i<n && nums[i] > nums[i-1]){
                i++;
                f = 1;
                cnt++;
            }
            
            ans = max(ans, cnt+1);
            if(f == 0)
                i++;
                
        }
        
        return ans;
    }
};