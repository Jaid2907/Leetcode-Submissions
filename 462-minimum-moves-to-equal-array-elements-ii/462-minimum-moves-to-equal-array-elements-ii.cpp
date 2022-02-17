class Solution {
public:
    int minMoves2(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        int n = nums.size();
        int s1 = 0, s2 = 0;
          if(n == 1)
              return 0;
          for(int i=0; i<n; i++)
          {
              s1 += abs(nums[n/2]-nums[i]);
              s2 += abs(nums[n/2-1]-nums[i]);
          }
        
        return min(s1,s2);
      
    }
};