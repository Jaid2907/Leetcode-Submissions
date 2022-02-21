class Solution {
public:
    void sortColors(vector<int>& nums) {
     int n = nums.size();
     int low = 0;
     int mid = 0;
     int high = n-1;
     int index = 0;
        while(mid<=high)
        {
           if(nums[mid] == 0)
           {
               swap(nums[mid],nums[low]);
               low += 1;
               mid +=1;
               
               
           }
            else if(nums[mid] == 1)
            {
                
                mid++;
                index++;
            }
            else
            {
                swap(nums[high],nums[mid]);
                high--;
                
                
                
            }
               
        }
    }
};