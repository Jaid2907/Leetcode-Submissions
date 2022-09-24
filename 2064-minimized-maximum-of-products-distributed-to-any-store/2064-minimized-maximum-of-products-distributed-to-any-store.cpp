int canDistribute (int n, int k, vector<int>& nums){
    
    int temp = 0;
    for(int i = 0; i<nums.size(); i++){
        
        if(nums[i]%k == 0)
            temp += nums[i]/k;
        else
            temp += nums[i]/k+1;
    }
    
    return temp;
}
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int low = 1, high = 1e5;
        int ans = 1;
        while(low < high){
            int mid = low + (high-low)/2;
            int temp = canDistribute(n,mid,quantities);
            if(temp>n){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        
        return low;
        
    }
};