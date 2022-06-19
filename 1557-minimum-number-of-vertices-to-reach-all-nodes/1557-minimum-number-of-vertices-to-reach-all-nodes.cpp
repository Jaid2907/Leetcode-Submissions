
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       
        vector<int> temp(n,0);
        
        for(auto it: edges){
            temp[it[1]]++;
        }
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(temp[i] == 0)
                ans.push_back(i);
        }
        return ans;
        
    }
};