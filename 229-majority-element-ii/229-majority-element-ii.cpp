class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = INT_MIN, c2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == c1)
                cnt1++;
            else if(nums[i] == c2)
                cnt2++;
            else if(cnt1 == 0)
            {
                c1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                c2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
                
        }
        
        cnt1 = 0;
        cnt2 = 0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] == c1)
                cnt1++;
            if(nums[i] == c2)
                cnt2++;
        }
        vector<int> ans;
        
        if(cnt1 > n/3)
            ans.push_back(c1);
        if(cnt2 > n/3)
            ans.push_back(c2);
        
        return ans;
    }
};