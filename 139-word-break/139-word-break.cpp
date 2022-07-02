class Solution {
public:
    
    bool helper (int start, int n, string s, unordered_map<string,int>& mp,vector<int>& dp){
        

        if(start == n){
            return true;
        }
        
        if(dp[start] != -1)
            return dp[start];
        
        for(int end = start+1; end<=n; end++){
            
            if((mp.find(s.substr(start,end-start)) != mp.end()) && helper(end,n,s,mp,dp))
                return dp[start] = true;
           
        }
        
        return dp[start] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map <string,int> mp;
        int n = s.size();
        
        vector<int> dp(n+1,-1);
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]]++;
        }
        
        if(mp.find(s) != mp.end())
            return true;
        
        
        return helper(0,n,s,mp,dp);
    }
};