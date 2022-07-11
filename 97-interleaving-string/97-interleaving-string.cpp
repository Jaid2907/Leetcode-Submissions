class Solution {
public:
    bool helper (int i, int j, int k , string& a, string& b, string& c,vector<vector<vector<int>>>& dp){
        
        if(k == c.size())
            return true;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        bool ans = false;
        
        if(i < a.size() && c[k] == a[i]){
           ans = ans || helper(i+1,j,k+1,a,b,c,dp);
        }
        if(j < b.size() && c[k] == b[j]){
            ans = ans || helper(i,j+1,k+1,a,b,c,dp);
        }
        
        return dp[i][j][k] =  ans;
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1 == "" && s2 == "" && s3 == "")
            return true;
        
        if(s3.size() != (s1.size() + s2.size()))
            return false;
        
        vector<vector<vector<int>>> dp (s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1,-1)));
        return helper(0,0,0,s1,s2,s3,dp);
    }
};