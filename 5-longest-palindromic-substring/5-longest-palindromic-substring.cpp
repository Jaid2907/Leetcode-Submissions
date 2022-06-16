class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(j == i)
                    dp[i][i] = true;
                else if(j == i+1)
                    dp[i][j] = s[i]==s[i+1]?true:false;
            }
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                
                if(i != j  && j != i+1)
                if(i+1<n && j>0)
                dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
            }
        }
        

        
        int ans = 0;
        int start = 0, end = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(dp[i][j]){
                    if(ans < (j-i+1)){
                        ans = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
            
        }
        
        string str = "";
        for(int i= start; i<=end; i++)
            str += s[i];
        return str;
    }
};