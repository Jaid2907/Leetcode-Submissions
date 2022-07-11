class compare{
  
    public:
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.first < b.first;
    }
};
class Solution {
public:
   
    int maxResult(vector<int>& nums, int k) {
        
        vector<int> dp(nums.size(), INT_MIN);
        int n = nums.size();
        
        dp[n-1] = nums[n-1];
        priority_queue <pair<int,int>, vector<pair<int,int>>, compare> pq;
        pq.push({dp[n-1],n-1});
        
        for(int i=n-2; i>=0; i--){
            
           while(true){
               if(pq.top().second-i<=k)
                   break;
               pq.pop();
           }
            
            dp[i] = max(dp[i],nums[i] + pq.top().first);
            pq.push({dp[i],i});
        }
        
       
        return dp[0];
    }
};