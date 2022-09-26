class Solution {
public:
    int minPartitions(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            ans = max(ans, s[i]-48);
        }
        
        return ans;
    }
};