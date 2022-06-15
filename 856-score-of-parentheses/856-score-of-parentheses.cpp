class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st; 
        int n = s.size();
        
        
        for(int i=0; i<n; i++){
            
            if(s[i] == '('){
                st.push(-1);
                
            }
            else{
                
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int a = 0;
                    while(st.top() != -1){
                        a += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*a);
                }
                    
            }
        }
        
        
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};