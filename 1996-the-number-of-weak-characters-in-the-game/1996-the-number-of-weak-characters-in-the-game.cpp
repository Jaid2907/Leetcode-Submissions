class Solution {
public:
    static bool compare (vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        
        sort(nums.begin(), nums.end(), compare);
        int curr_maxi = INT_MIN, prev_maxi = INT_MIN;
        int cnt = 0;
        int n = nums.size();
        
      
        int i = n-1;
        while(i>=0){
            int curr = nums[i][0];
            while( i >=0 && nums[i][0] == curr){
                
                if(nums[i][1] < prev_maxi)
                    cnt++;
                curr_maxi = max(curr_maxi, nums[i][1]);
                i--;
            }
            
            prev_maxi = max(prev_maxi,curr_maxi);
            curr_maxi = INT_MIN;
            
                
        }
        
        return cnt;
    }
};