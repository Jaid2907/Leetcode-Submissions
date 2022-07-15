class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        int n = height.size();
        vector<int> left (n,-1);
        vector<int> right(n,-1);
        int maxi_left = INT_MIN;
        int maxi_right = INT_MIN;
        
        for(int i = 0, j= n-1; i<n; i++, j--){
            
            maxi_left = max(maxi_left,height[i]);
            left[i] = maxi_left;
            
            maxi_right = max(maxi_right,height[j]);
            right[j] = maxi_right;
        }
        
        
        for(int i = 0; i<n; i++){
            
            int a = min(left[i],right[i]);
            ans += a - height[i] > 0? a - height[i]: 0;
        }
        return ans;
    }
};