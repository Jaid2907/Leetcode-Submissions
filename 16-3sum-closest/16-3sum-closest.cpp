class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        int closest_sum = 0;
        int sum = 0;
        int flag = 0;
        sort(nums.begin(),nums.end());
        for(int i=1; i<n-1; i++)
        {
            int j = 0;
            int k = n-1;
            
            while(j<i && k>i)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                if( abs(target-closest_sum) > abs(target-sum) && flag == 1)
                    closest_sum = sum;
                
                if(flag == 0)
                {
                    closest_sum = sum;  
                    flag = 1;
                }
                if(sum>target)
                {
                    k--;
                }
                else if(sum<target)
                {
                    j++;
                }
                else
                {
                    break;
                }
                
                
            }
            
        }
        
        return closest_sum;
    }
};