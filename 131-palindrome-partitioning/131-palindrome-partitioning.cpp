class Solution {
public:
    bool isPalindrome(string& s){
        
        int n = s.size();
        
        for(int i = 0; i<n/2; i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        
        return true;
    }
    void helper (int i,int n, string& s, vector<vector<string>>& ans, vector<string>& ds, vector<vector<bool>>& dp){
        if(i == n){
            ans.push_back(ds);
            return ;
        }
        
        for(int j = i; j<n; j++){
            string str = s.substr(i,j-i+1);
            if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                dp[i][j] = true;
                ds.push_back(str);
                helper(j+1,n,s,ans,ds,dp);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        helper(0,n,s,ans,ds,dp);
        
        return ans;
    }
};