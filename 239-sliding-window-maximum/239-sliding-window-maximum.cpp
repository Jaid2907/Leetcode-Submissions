class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    multiset<int> s;
    
    int n = nums.size();
    vector<int> ans;
    if(k>n)
    {
        ans.push_back(*max_element(nums.begin(),nums.end()));
        return ans;
    }
    for(int i=0; i<k; i++)
    s.insert(nums[i]);

    
    ans.push_back(*s.rbegin());

    for(int i=k; i<n; i++)
    {
        s.insert(nums[i]);
        auto it = s.find(nums[i-k]);
        s.erase(it);
        ans.push_back(*s.rbegin());
    }

    return ans;
    }
};