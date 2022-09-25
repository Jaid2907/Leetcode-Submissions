class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> decr(n);
        vector<int> incr(n);
        vector<int> ans;
        
        int start = nums[0], end = nums[0];
        int len = 0;
        
        for(int i = 0; i<n; i++){
            
            if(nums[i]<=start){
                len++;
            }
            else
                len = 1;
            decr[i] = len;
            start = nums[i];
        }
        
        start = nums[0];
        len = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]>=start){
                len++;
            }
            else{
                len = 1;
            }
            incr[i] = len;
            start = nums[i];
        }
        
//         for(auto it: incr){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//         for(auto it: decr){
//             cout<<it<<" ";
//         }
//         cout<<endl;
    
        for(int i = k; i<n-k; i++){
            if(incr[i+k]-incr[i+1] >=(k-1) && decr[i-1] - decr[i-k] >= (k-1)){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};