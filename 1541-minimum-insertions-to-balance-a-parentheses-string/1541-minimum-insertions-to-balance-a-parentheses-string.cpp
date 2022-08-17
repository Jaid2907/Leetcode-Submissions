class Solution {
public:
    int minInsertions(string s) {
        
        stack<char> st;
        int n = s.size();
        int cnt = 0;
        int i = 0;
        
        
        while(i<n){
            
            if(s[i] == '('){
                st.push(s[i]);
                i++;
            }
            else{
                if(!st.empty()){
                    if(i+1<n && s[i] == s[i+1]){
                        st.pop();
                        i += 2;
                    }
                    else if(i+1 == n){
                        st.pop();
                        cnt++;
                        i++;
                    }
                    else{
                        st.pop();
                        cnt++;
                        i++;
                    }
                }
                else{
                    
                    if(i+1<n && s[i] == s[i+1]){
                        cnt++;
                        i += 2;
                    }
                    else if(i+1 == n){
                        cnt += 2;
                        i++;
                    }
                    else{
                        cnt += 2;
                        i++;
                    }
                    
                }
                
            }
        }
        
        while(!st.empty()){
            cnt += 2;
            st.pop();
        }
        
        return cnt;
    }
};