class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = max(gain[0],0);
        int temp = gain[0];
        
        for(int i = 1; i<n; i++){
            temp += gain[i];
            ans = max(ans, temp);
        }
        
        return ans;
        
    }
};