class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++)
        {
            int front = i+1;
            int rear = n-1;
            int target = -nums[i];
            while(front<rear)
            {
                if(nums[front]+nums[rear]<target)
                {
                    front++;
                }
                else if(nums[front]+nums[rear]>target)
                {
                    rear--;
                }
                else
                {
                    ans.push_back({nums[i],nums[front],nums[rear]});
                    int a = nums[front];
                    while(front<rear && nums[front] == a)
                        front++;
                    a = nums[rear];
                    while(rear>front && nums[rear] == a)
                        rear--;
                }
            }
            
            while(i+1<n && nums[i+1] == nums[i])
                i++;
        }
        
        return ans;
    }
};