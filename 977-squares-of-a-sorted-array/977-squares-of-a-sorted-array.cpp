class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     
        vector<int> ans;
        int pos_start;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]>=0)
            {
                pos_start = i;
                break;
            }
            nums[i] = abs(nums[i]);
        }
        
        reverse(nums.begin(),nums.begin()+pos_start);
        int i = 0;
        int j = pos_start;
        
        
        while(i<pos_start && j<n)
        {
            if(nums[i]<nums[j])
            {
                ans.push_back(nums[i]*nums[i]);
                i++;
            } 
            else
            {
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
                
        }
        
        while(i<pos_start)
        {
            ans.push_back(nums[i]*nums[i]);
            i++;
        }
        while(j<n)
        {
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        
        
        return ans;
    }
};