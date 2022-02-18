class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // A kind of real interview question
        // We can go from O(n^2) to O(nlogn) to O(n) with constant space;
        
        // So in case of doing it in O(n) time and O(1) space we will be using the array itself as a hash map by negating the element at nums[i]-1. if it is already -ve again while checking then it is a duplicate.
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[abs(nums[i])-1] >0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            else
                ans.push_back(abs(nums[i]));
        }
        
        return ans;
    }
};