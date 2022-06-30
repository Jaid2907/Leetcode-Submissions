class Solution {
public:
    bool helper(int i, int j, string& pattern , string& text, vector<vector<int>>& dp){
    
    
    if(j == text.size() && i == pattern.size())
        return true;
    if(i == pattern.size() && j!= text.size())
        return false;
    
    if(j == text.size() && i<pattern.size()){
        
        while(i<pattern.size() && pattern[i] == '*')
            i++;
        if(i == pattern.size())
            return true;
        else
            return false;
    }
    
    
        
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    bool b = false, c = false;
    
    if(pattern[i] == '?' || pattern[i] == text[j])
         return dp[i][j] = helper(i+1,j+1,pattern, text,dp);
    else if(pattern[i] == '*'){
        
        b = helper(i+1,j,pattern,text,dp);
        c = helper(i,j+1,pattern,text,dp);
       
        return dp[i][j] = b || c ;
    }
    else 
        return dp[i][j] = false;
    
    
        
}
    bool isMatch(string text, string pattern) {
        vector<vector<int>> dp(pattern.size(), vector<int>(text.size(), -1));
        return helper(0,0,pattern,text,dp);
    }
};