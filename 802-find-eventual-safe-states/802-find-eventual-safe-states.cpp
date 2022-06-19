class Solution {
public:
    bool dfs(int node , vector<int>& visited, vector<int>& safe, vector<vector<int>>& graph){
        
        if(safe[node] != -1)
            return safe[node];
        
        if(visited[node])
            return false;
        
        
        
        visited[node] = 1;
        bool ans = true;
        
        for(auto it: graph[node]){
            
            ans = ans && dfs(it,visited,safe,graph);
            
        }
        
        return safe[node] = ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> safe(n,-1);
        
        for(int i=0; i<n; i++){
            if(graph[i].size() == 0){
                safe[i] = 1;
            }
        }
        
        for(int i=0; i<n; i++){
            
            if(!visited[i]){
                dfs(i,visited,safe,graph);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(safe[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
    
};