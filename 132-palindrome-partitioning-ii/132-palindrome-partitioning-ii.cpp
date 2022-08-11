class Solution {
public:
    bool isPalindrome(string& s){
        int n = s.size();
        
        for(int i = 0; i<n/2; i++){
            if(s[i] != s[n-1-i])
                return false;
        }
        
        return true;
    }
    int helper(string& s, int i,int n, vector<vector<int>>& dp, vector<int>& dp_1){
        
        if(i == n){
            return 0;
        }
        if(dp_1[i] != -1)
            return dp_1[i];
        int ans = INT_MAX;
        string sub = "";
        for(int j = i; j<n; j++){
            
            if(i>0 && j>0 && s[i] == s[j] && dp[i-1][j-1] == 1){
                dp[i][j] = 1;
                ans =  min (ans, 1 + helper(s,j+1,n,dp,dp_1));
            }
            sub += s[j];
            // string sub = s.substr(i,j-i+1);
            
            if(isPalindrome(sub)){
                dp[i][j] = 1;
                ans = min(ans, 1 + helper(s,j+1,n,dp,dp_1));
            }
            
        }
        
        return dp_1[i]  = ans;
    }
    int minCut(string str) {
        int n = str.size();
        vector<int> dp_1(n,-1);
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        return helper(str,0,n,dp,dp_1)-1;   
    }
};