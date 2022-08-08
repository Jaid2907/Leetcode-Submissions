class Solution {
public:
    int mod = 1e9+7;
//     int helper (int i,int n, char prev, vector<vector<int>>& dp){
        
//         if(i == n-1)
//             return 1;
//         if(dp[i][prev] != -1)
//             return dp[i][prev];
        
//         vector<long long int> temp(5,0);
        
//         if(prev == 'a'){
//             temp[0] = helper(i+1,n,'e',dp)%mod;
//         }
//         else if(prev == 'e'){
//             temp[1] = (helper(i+1,n,'a',dp)%mod + helper(i+1,n,'i',dp)%mod)%mod;
//         }
//         else if(prev == 'i'){
//             temp[2] = ((helper(i+1,n,'a',dp)%mod) + 0ll + (helper(i+1,n,'e',dp)%mod) + (helper(i+1,n,'o',dp)%mod) + (helper(i+1,n,'u',dp)%mod))%mod;
//         }
//         else if(prev == 'o'){
//             temp[3] = (helper(i+1,n,'i',dp)%mod + helper(i+1,n,'u',dp)%mod)%mod;
//         }
//         else {
//             temp[4] = helper(i+1,n,'a',dp)%mod;
//         }
//         int ans = 0;
        
//         for(int i = 0; i<5; i++){
//             ans = (ans + temp[i])%mod;
//         }
//         return dp[i][prev] = ans%mod;
//     }
    int countVowelPermutation(int n) {
        
        
        vector<char> vowels = {'a','e','i','o','u'};
        vector<vector<int>> dp(n,vector<int>(256,0));
        
        for(int i = 0; i<5; i++)
            dp[0][vowels[i]] = 1;
        
        for(int i = 1; i<n; i++){
            
            for(int j = 0; j<5; j++){
                char prev = vowels[j];
                
                if(prev == 'a'){
                    dp[i][prev] = (dp[i-1]['e']%mod + 0ll + dp[i-1]['i']%mod + dp[i-1]['u']%mod)%mod;
                }
                else if(prev == 'e'){
                    dp[i][prev] = (dp[i-1]['a']%mod + 0ll + dp[i-1]['i']%mod)%mod;
                }
                else if(prev == 'i'){
                    dp[i][prev] = (dp[i-1]['e']%mod + dp[i-1]['o']%mod)%mod;
                }
                else if(prev == 'o'){
                    dp[i][prev] = dp[i-1]['i']%mod;
                }
                else{
                    dp[i][prev] = (dp[i-1]['i']%mod + dp[i-1]['o']%mod)%mod;
                }
                
            }
        }
        
        
        
        int ans = 0;
        
        for(int i = 0; i<5; i++){
            
            ans = (ans%mod + dp[n-1][vowels[i]]%mod)%mod;
        }
        
        return ans;
    }
};