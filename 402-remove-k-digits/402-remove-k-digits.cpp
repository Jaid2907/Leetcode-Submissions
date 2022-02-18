class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        st.push(num[0]);
        if(k == n)
            return "0";
        for(int i=1; i<n; i++)
        {
              while(!st.empty() && num[i]<st.top() && k)
                {
                    k--;
                    st.pop();
                }
            st.push(num[i]);
            
        }
        while(k)
        {
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
       
        while(ans.size()>0 && ans[ans.size()-1] == '0')
            ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans.size() == 0)
            ans += "0";
        return ans;
        
    }
};