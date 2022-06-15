int mod = 1e9+7;
class Solution {
public:
    int count (int i, string& s, int n, vector<int>& dp){
        if(i >= n){
            return 1;
        }
        
        if(dp[i] != -1)
            return dp[i];
        int a = 0, b = 0, c = 0, d = 0;
        
        a = count(i+1,s,n,dp)%mod;
        
        if(i+1<n && s[i] == s[i+1])
            b = count(i+2,s,n,dp)%mod;
        
        if(i+2<n && s[i] == s[i+1] && s[i+1] == s[i+2])
            c = count(i+3,s,n,dp)%mod;
        
        if((s[i] == '7' || s[i] == '9') && i+3<n && s[i] == s[i+1] && s[i+1]==s[i+2] && s[i+2] == s[i+3])
            d =  count(i+4,s,n,dp)%mod;
        
        return dp[i] = ((a+b)%mod+(c+d)%mod)%mod;
        
        
    }
    int countTexts(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return count(0,s,s.size(),dp);
        
        
    }
};