class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
         
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        for(int i=0; i<n; i++)
            pq.push({nums[i],i});
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++)
            ans[i] = nums[ans[i]];
        
        return ans;
            
    }
};