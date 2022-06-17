class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
    reverse(t.begin(), t.end());
 
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    
    for(int i=0; i<n; i++){
        if(s[0] == t[i])
            dp[0][i] = 1;
        else
            if(i>=1)
            dp[0][i] = dp[0][i-1];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int a = INT_MIN, b = INT_MIN, c = INT_MIN;
            if(s[i] == t[j])
                if(j>=1)
                a = 1 + dp[i-1][j-1];
            else
                a = 1;
            
            b = dp[i-1][j];
            if(j-1>=0)
            c = dp[i][j-1];
            
            dp[i][j] = max(max(a,b),c); 
           
        }
    }

    
    return dp[n-1][n-1];
    }
};