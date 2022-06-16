class Solution {
public:

    int coinChange(vector<int>& num, int x) {
    vector<int> dp(x+1,0);
    unordered_map<int,int> mp;
        
    int n = num.size();
        
    for(auto it: num){
        mp[it]++;
    }
        
    for(int i=0; i<=x; i++){
        if(mp.find(i) != mp.end())
            dp[i] = 1;
    }
        
    int ans = INT_MAX;
        
    for(int i=1; i<=x; i++){
        ans = INT_MAX;
        
        for(int j=0; j<n; j++){
            if(i-num[j]>=0)
            ans = min(ans, dp[i-num[j]]);
        }
        
        if(ans == INT_MAX)
            dp[i] = INT_MAX;
        else
            dp[i] = 1+ans;
        
    }
        
    return dp[x] == INT_MAX?-1:dp[x];
    }
};