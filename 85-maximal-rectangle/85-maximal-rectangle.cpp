class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //Computing next and prev smaller of each number
        
        int n = heights.size();
        stack<pair<int,int>> st;
        vector<int> next(n,n-1);
        vector<int> prev(n,0);
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
            
            if(!st.empty() && st.top().first < heights[i]){
                
                prev[i] = st.top().second;
            }
            else{
                prev[i] = -1;
            }
            
            st.push({heights[i],i});
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i = n-1; i>=0; i--){
            
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
            
            if(!st.empty() && st.top().first < heights[i]){
                next[i] = st.top().second;
            }
            else{
                next[i] = n;
            }
            st.push({heights[i],i});
        }
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            ans = max(ans, (next[i]-prev[i]-1)*heights[i]);
        }
        return ans;
       
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 1 && n == 1)
            return matrix[0][0] == '1';
        vector<vector<pair<int,int>>> dup(m,vector<pair<int,int>>(n));
        
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
        
        
        for(int j = 0; j<n; j++){
            
            stack<vector<int>> st;
            int a,b;
            vector<int> down(m), up(m);
                
            for(int i = m-1; i>=0; i--){
                
                
                    while(!st.empty() && st.top()[0] == 1 && st.top()[1] >= dup[i][j].second)
                    st.pop();
                
                    if(!st.empty()){
                        down[i] = st.top()[2];
                    }
                    else{
                        down[i] = m;
                    }   
                st.push({matrix[i][j] == '0'? 0:1 ,dup[i][j].second , i});
                   
            }
            
            while(!st.empty())
                st.pop();
            
            for(int i = 0; i<m; i++){
                
                while(!st.empty() && st.top()[0] == 1 && st.top()[1] >= dup[i][j].second)
                    st.pop();
                
                if(!st.empty() ){
                    up[i] = st.top()[2];
                }
                else{
                    up[i] = -1;
                }
                
                st.push({matrix[i][j] == '0'? 0:1 ,dup[i][j].second , i});
                
                
            }
            
            for(int i=0; i<m; i++){
                
                dup[i][j].first = down[i]-up[i]-1;
            }
            
        }
            
        
    
        

        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1')
                {
                     ans = max(ans, (dup[i][j].first * (dup[i][j].second-j)));
                }
               
            }
        }
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                     cout<<"("<<dup[i][j].first<<","<<dup[i][j].second<<")"<<" ";
                
//             }
//             cout<<endl;
//         }
        
      
        
        return ans;
    }
};