class Solution {
public:
    bool helper (int i, string& s, int cnt_open,vector<vector<int>>& dp){
        
        if(i == s.size())
            return cnt_open == 0;
        
        if(cnt_open<0)
            return false;
        
        if(dp[i][cnt_open] != -1)
            return dp[i][cnt_open];
        
        bool ans = false;
        
        if(s[i] == '(')
            ans =  helper(i+1,s,cnt_open+1,dp);
        else if(s[i] == ')')
            ans = helper(i+1,s,cnt_open-1,dp);
        else{
            
            ans = helper(i+1,s,cnt_open+1,dp) || helper(i+1,s,cnt_open-1,dp) || helper(i+1,s,cnt_open,dp);
        }
        
        return dp[i][cnt_open] =  ans;
    }
    bool checkValidString(string s) {
     
        vector<vector<int>> dp (s.size()+1, vector<int>(s.size()+1,-1));
        return helper(0,s,0,dp);
    }
};