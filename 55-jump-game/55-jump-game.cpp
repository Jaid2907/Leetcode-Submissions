class Solution {
public:
    bool canJump(vector<int>& nums) {
     
        queue<pair<int,int>> q;
        int n = nums.size();
        vector<int> visited(n,0);
        q.push({nums[0],0});
        visited[0] = 1;
        
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
                
            if(t.second == n-1)
                return true;
            for(int i=1; i<=t.first && i+t.second < n; i++)
            {
                if(!visited[i+t.second])
                {   if(i+t.second == n-1)
                    return true;
                    q.push({nums[i+t.second],i+t.second});
                    visited[i+t.second] = 1;
                }
                
                
            }
            
        
        }
        
        return false;
    }
};