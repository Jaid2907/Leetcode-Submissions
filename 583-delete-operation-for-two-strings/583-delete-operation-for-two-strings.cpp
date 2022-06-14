class Solution {
public:
    int minDistance(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0)); 
        
        for(int i=1; i<=text1.length(); i++)
        {
            for(int j=1; j<=text2.length(); j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int ans = text1.length() + text2.length() - 2*dp[text1.size()][text2.size()];
        return ans;
    }
};