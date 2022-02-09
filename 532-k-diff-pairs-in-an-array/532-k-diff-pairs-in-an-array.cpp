class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        set<pair<int,int>> s;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(abs(nums[j]-nums[i])==k)
                {
                    cnt++;
                    if(nums[i]<nums[j])
                    {
                        s.insert({nums[i],nums[j]});
                    }
                    else
                    {
                        s.insert({nums[j],nums[i]});
                    }
                    
                }
            }
        }
        
        return s.size();
        
    }
};