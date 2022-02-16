class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,greater;
        int n = nums.size();
        int freq = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == pivot)
            {
                freq++;
            }
            else if(nums[i]<pivot)
            {
                less.push_back(nums[i]);
            }
            else
            {
                greater.push_back(nums[i]);
            }
                
        }
        
        int i = 0, k = 0;
        while(i<less.size())
            nums[k++] = less[i++];
        i = 0;
        while(freq--)
            nums[k++] = pivot;
        while(i<greater.size())
            nums[k++] = greater[i++];
        
        return nums;
        
    }
};