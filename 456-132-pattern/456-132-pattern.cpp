class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int candidate = INT_MIN;
        
        for(int i = n-1; i>=0; i--){
            
             if(nums[i] < candidate){
                return true;
            }
            while(!st.empty() && st.top() < nums[i]){
                candidate = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        
        return false;
    }
};