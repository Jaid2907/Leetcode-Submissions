class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<pair<int,int>>> dup(m,vector<pair<int,int>>(n));
        
        
        for(int j = 0; j<n; j++){
            stack<pair<char,int>> st;
            
            for(int i = m-1; i>=0; i--){
                
                
                    while(!st.empty() && st.top().first == '1')
                    st.pop();
                
                    if(!st.empty() && st.top().first == '0'){
                        dup[i][j].first = st.top().second;
                    }
                    else{
                        dup[i][j].first = m;
                    }   
                st.push({matrix[i][j],i});
                   
            }
        }
        
       for(int i = 0; i<m; i++){
           stack<pair<char,int>> st;
           
           for(int j=n-1; j>=0; j--){
               
               while(!st.empty() && st.top().first == '1')
                   st.pop();
               
               if(!st.empty() && st.top().first == '0'){
                   dup[i][j].second = st.top().second;
               }
               else{
                   dup[i][j].second = n;
               }
               
               st.push({matrix[i][j],j});
           }
       }
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(matrix[i][j] == '1'){
                    int mini_spread = INT_MAX;
                    
                    for(int k = i; k<dup[i][j].first; k++){    
                      mini_spread = min(mini_spread,dup[k][j].second);
                        ans = max(ans,(mini_spread-j)*(k-i+1));
                    }
                    
                    
                        
                        
                }
            }
        }
        
        
            
        return ans;
    }
};