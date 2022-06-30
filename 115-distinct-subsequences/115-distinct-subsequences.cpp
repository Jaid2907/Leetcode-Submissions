int mod = 1e9+7;
class Solution {
public:
    int helper (int i, int j, string &text, string &pattern, vector<vector<int>>& dp){
    
    if(j == pattern.size())
        return 1;
    
    if(i == text.size())
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int a = 0, b = 0;
    if(text[i] == pattern[j]){
        a = helper(i+1,j+1,text,pattern,dp)%mod;
    }
    
        b = helper(i+1,j,text,pattern,dp) % mod;
    
    
    return dp[i][j] = (a+b)%mod;
    
    
}
    int numDistinct(string s, string t) {
        
        int ls = s.size();
        int lt = t.size();
        
        vector<vector<int>> dp (ls+1, vector<int> (lt+1,-1));
        
        
        return helper(0,0,s,t,dp);
        
        if(s[0] == t[0])
            dp[0][0] = 1;
        
        for(int i=1; i<ls; i++){
            if(t[0] == s[i]){
                dp[0][i] = 1 + dp[0][i-1];
            }
            else
                dp[0][i] = dp[0][i-1];
        }
        
        for(int i=1; i<lt; i++){
            for(int j=0; j<ls; j++){
                
                int a = 0, b = 0;
                
                if(t[i] == s[j]){
                    if(j>0)
                        a = 1 + dp[i-1][j-1];   
                }
                
                if(j>0)
                b = dp[i][j-1];
                
                dp[i][j] = a+b;
            }
        }
        
        return dp[lt-1][ls-1];
    }
};