class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.size();
        int op_cnt = 0;
        stack <char> st;
        string ans = "";
        stack <char> st2;
        for(int i=0; i<n; i++)
        {
            if(s[i] == ')' && op_cnt>0)
            {
                st.push(s[i]);
                op_cnt--;
            }
            else if(s[i] == ')' && op_cnt<=0)
            {
                continue;
            }
            else if(s[i] == '(')
            {
                st.push(s[i]);
                op_cnt++;
            }
            else
            {
                st.push(s[i]);
            }
            
        }
        
        while(op_cnt--)
        {
            while(st.top() != '(')
            {
                char ch = st.top();
                st2.push(ch);
                st.pop();
            }
            st.pop();
            
            while(!st2.empty())
            {
                char ch = st2.top();
                st.push(ch);
                st2.pop();
            }
            
        }
        
        while(!st.empty())
        {
            char ch = st.top();
            ans += ch;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};