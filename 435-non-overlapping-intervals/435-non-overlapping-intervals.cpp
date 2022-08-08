class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[1] == b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end(),compare);
    int prevEnd = nums[0][1];
    int prevStart = nums[0][0];
    int freq = 1;
    for(int i = 1; i<n; i++){
        if(nums[i][0] >= prevEnd){
            freq++;
            prevEnd = nums[i][1];
        }
    }
    
    return n-freq;
    }
};