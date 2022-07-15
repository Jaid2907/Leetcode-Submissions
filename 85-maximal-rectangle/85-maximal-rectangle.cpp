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
        vector<int> heights(n,0);
        int ans = 0;
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            
            ans = max(ans,largestRectangleArea(heights));
        }
        
        return ans;
    }
};