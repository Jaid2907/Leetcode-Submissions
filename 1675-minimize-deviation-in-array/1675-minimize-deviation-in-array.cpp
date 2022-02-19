class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> pq;
        int n = nums.size();
        int minimum = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(nums[i] & 1)
                nums[i] *= 2;
            minimum = min(minimum,nums[i]);
            
            pq.push(nums[i]);
        }
        int max = INT_MIN;
        int diff = INT_MAX;
        while(pq.top()%2 == 0)
        {
            int a = pq.top();
            pq.pop();
            diff = min(a - minimum,diff);
            minimum = min(minimum,a/2);
            pq.push(a/2);
        }
        diff = min(diff,pq.top()-minimum);
        return diff;
        
    }
};