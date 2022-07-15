class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        int n = height.size();
        vector<int> left (n,-1);
        vector<int> right(n,-1);
        int maxi = INT_MIN;
        
        for(int i = 0; i<n; i++){
            maxi = max(maxi,height[i]);
            left[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i = n-1; i>=0; i--){
            maxi = max(maxi, height[i]);
            right[i] = maxi;
        }
        
        
        for(int i = 0; i<n; i++){
            
            int a = min(left[i],right[i]);
            ans += a - height[i] > 0? a - height[i]: 0;
        }
        return ans;
    }
};