class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n-3; i++)
        {   int a = nums[i];
            for(int j=i+1; j<n-2; j++)
            {
                int b = nums[j];
                
                int new_target = target -(a+b);
                
                int front = j+1;
                int rear = n-1;
                
                while(front<rear)
                {
                    if(nums[front]+ nums[rear] > new_target)
                    {
                        rear--;
                        
                    }
                    else if(nums[front]+nums[rear]<new_target)
                    {
                        front++;
                    }
                    else
                    {
                        ans.push_back({a,b,nums[front],nums[rear]});
                        
                        int temp = nums[front];
                        while(front<rear && nums[front]==temp)
                            front++;
                        temp = nums[rear];
                        while(front<rear && nums[rear] == temp)
                            rear--;
                    }
                        
                }
                
                while(j+1<n && nums[j+1]==nums[j])
                    j++;
                
            }
         
         while(i+1<n && nums[i+1] == nums[i])
             i++;
        }
        
        return ans;
    }
};