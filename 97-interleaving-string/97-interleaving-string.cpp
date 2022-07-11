class Solution {
public:
    bool helper (int i, int j, int k , string& a, string& b, string& c,vector<vector<int>>& dp){
        
        if(i == a.size()){
            return b.substr(j) == c.substr(k);
        }
        
        if(j == b.size()){
            return a.substr(i) == c.substr(k);
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool ans = false;
        
        if(i < a.size() && c[k] == a[i]){
           ans = ans || helper(i+1,j,k+1,a,b,c,dp);
        }
        if(j < b.size() && c[k] == b[j]){
            ans = ans || helper(i,j+1,k+1,a,b,c,dp);
        }
        
        return  dp[i][j] = ans;
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1 == "" && s2 == "" && s3 == "")
            return true;
        
        if(s3.size() != (s1.size() + s2.size()))
            return false;
        vector<vector<int>> dp (s1.size()+1, vector<int>(s2.size()+1,-1));
        
        for(int i=s1.size(); i>=0; i--){
            for(int j=s2.size(); j>=0; j--){
                int k = i+j;
                
                if(i == s1.size() && j == s2.size())
                    dp[i][j] = 1;
                else if(s1[i] == s3[k] && s2[j] == s3[k])
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                else if(s1[i] == s3[k])
                    dp[i][j] = dp[i+1][j];
                else if(s2[j] == s3[k])
                    dp[i][j] = dp[i][j+1];
                else 
                    dp[i][j] = false;
                
            }
        }
        
        return dp[0][0];
        
        
        
    }
};