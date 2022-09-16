class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int max_pos = 0, min_pos = 0;
        int maxi = INT_MIN, mini = INT_MAX;
        
        for(int i = 0; i<n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                max_pos = i;
            }
            
            if(nums[i] < mini){
                mini = nums[i];
                min_pos = i;
            }
        }
        
        if(min_pos > max_pos)
            swap(min_pos,max_pos);
        
        int a = min_pos+1 + n - max_pos;
        int b = n-min_pos;
        int c = max_pos+1;
        
        return min({a,b,c});
    }
};