class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m,false);
        
        for(int i = 0; i<m; i++){
            
            int start = l[i];
            int end = r[i];
            int flag = 0;
            
            vector<int> temp;
            
            for(int j = start; j<=end; j++){
             temp.push_back(nums[j]);
            }
            
            sort(temp.begin(), temp.end());
            
            int d = temp[1]-temp[0];
            
            for(int i = 1; i<temp.size(); i++){
                if((temp[i] - temp[i-1]) != d){
                    flag = 1;
                    break;
                }
            }
            
            if(!flag)
                ans[i] = true;
        }
        
        return ans;
    }
};