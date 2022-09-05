class Solution {
public:

    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack <int> s;
        string res = "";
        
        for(int i = 0; i<=n; i++){
            s.push(i+1);
            
            if(i == n || pattern[i] == 'I'){
                while(!s.empty()){
                    res += to_string(s.top());
                    s.pop();
                }
            }
        }
        
        return res;
        
        
        
    }
};