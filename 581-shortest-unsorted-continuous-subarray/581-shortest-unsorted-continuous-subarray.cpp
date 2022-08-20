class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        
        sort(temp.begin(),temp.end());
        int start = -1, end = 0;
        int flag = 0;
        
        for(int i = 0; i<n; i++){
            if(nums[i] == temp[i])
                continue;
            if(flag == 0){
                flag = 1;
                start = i;
            }else{
                end = i;
            }
            
        }
        
        return start == -1 ? 0 : end-start+1;
        
    }
};