class Solution {
public:
    int helper (int i, vector<int>& days, vector<int>& cost, int n, vector<int>& dp){
        if(i >= days.size()){
            return 0;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        
        a = cost[0] + helper(i+1,days,cost,n,dp);
        
        int j = i;
        while(j<n && days[j]<days[i]+7)
            j++;
        b = cost[1] + helper(j,days,cost,n,dp);
        
        j = i;
        while(j<n && days[j]<days[i]+30)
            j++;
        c = cost[2] + helper(j,days,cost,n,dp);
        
        return dp[i] = min(min(a,b),c);
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, -1);
        return helper(0,days,costs,days.size(),dp);
    }
};