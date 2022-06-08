class Solution {
public:
    void dfs(int curr,vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& temp ){
        if(curr == graph.size()-1){
            ans.push_back(temp);
            return ;
        }
        
        
        
        for(auto it: graph[curr]){
            
                temp.push_back(it);
                dfs(it,graph,ans,temp);
                temp.pop_back();
            
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        temp.push_back(0);
        dfs(0,graph,ans,temp);
        
        return ans;
    }
};