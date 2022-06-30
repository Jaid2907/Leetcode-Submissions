class Solution {
public:
    int helper (int i, int j, string s, string t, vector<vector<int>>& dp){
        
        if(j == t.size())
            return s.size()-i;
        
        if(i == s.size())
            return t.size()-j;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int a = 0, b = 0, c = 0, d = 0;
        if(s[i] == t[j]){
            a = helper(i+1,j+1,s,t,dp);
        }
        else{
            //Insert
            b = 1 + helper(i,j+1,s,t,dp);
            
            //Replace
            c = 1 + helper(i+1,j+1,s,t,dp);
            
            //Delete
            d = 1 + helper(i+1,j,s,t,dp);
            
        }   
        
        return dp[i][j] =  a + min(min(d,b),c);
    }
    int minDistance(string word1, string word2) {
        
        // if(word1.size() < word2.size())
        //     swap(word1,word2);
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(),-1));
        return helper(0,0,word1,word2,dp);
    }
};