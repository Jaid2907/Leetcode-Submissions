class Solution {
public:
    int Decodeways (string s, int i, int n, vector<int>& dp)
    {
        if( i==n-1 && s[i] != '0')
            return 1;
        else if(i==n-1)
            return 0;
        if(i == n)
            return 1;
        
        
        if(dp[i] != -1)
            return dp[i];
        
         long long int a = 0, b = 0;
        if(s[i] != '0')
        a =  Decodeways(s,i+1,n,dp);
        if(i+1<n)
        {
            string temp = "";
            temp.push_back(s[i]);
            temp.push_back(s[i+1]);
            
            if(temp>="10" && temp<="26")
                b = Decodeways(s,i+2,n,dp);
        }
        
        return dp[i] = a+b;
    }
    int numDecodings(string s) {
        
        
        int n = s.size();
        vector<int> dp(n+2,-1);
        if(n == 1 && s[0] == '0')
            return 0;
       return Decodeways(s,0,n,dp);
    }
};