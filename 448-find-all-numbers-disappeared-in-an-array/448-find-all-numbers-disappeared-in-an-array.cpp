class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // This quesiton is same as returning duplicates in array containing elements from 1 to n. 
        // Here also we use the given array as a hashmap by negating the element present at index of nums[i].
        
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            if(nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        
        for(int i=0; i<n; i++)
            if(nums[i]>0)
                ans.push_back(i+1);
        
        return ans;
            
    }
};