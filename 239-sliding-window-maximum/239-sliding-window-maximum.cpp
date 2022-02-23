class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Clever Use of deque !!!
        vector<int> ans;
        int n = nums.size();
        deque <int> dq;
        
        for(int i=0;i<k; i++)
        {
            while(!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            
            if(dq.empty() || nums[i]>dq.front())
                dq.push_front(nums[i]);
            else
                dq.push_back(nums[i]);
        }
        
        ans.push_back(dq.front());
        
        for(int i=k; i<n; i++)
        {
            if(!dq.empty() && dq.front() == nums[i-k])
                dq.pop_front();
            
            while(!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            
            if(dq.empty() || nums[i]>dq.front())
                dq.push_front(nums[i]);
            else
                dq.push_back(nums[i]);
            
            ans.push_back(dq.front());
            
            
        }
        
        return ans;
    }
};