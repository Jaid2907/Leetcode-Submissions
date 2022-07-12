class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        vector<int> ans(n,-1);
        stack <int> st;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++)
            mp[nums2[i]] = i;
        
        st.push(nums2[n-1]);
        
        for(int i=n-2; i>=0; i--){
            
            while(!st.empty() && st.top()<nums2[i])
                st.pop();
            
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = -1;
            }
            
            st.push(nums2[i]);
        }
        vector<int> final_ans(nums1.size(),-1);
        
        for(int i=0; i<nums1.size(); i++){
            final_ans[i] = ans[mp[nums1[i]]];
        }
        
        return final_ans;
        
        
    }
};