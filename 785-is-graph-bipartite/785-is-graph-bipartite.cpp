class Solution {
public:
    bool isNotBipartite(int parent, int curr, vector<vector<int>>& graph, vector<int>& visited, vector<int>& color )
    {
        visited[curr] = 1;
        color[curr] = !color[parent];
        bool a = false;
        for(auto it: graph[curr])
        {
            if(!visited[it])
            {
                a = isNotBipartite(curr, it, graph, visited, color);
                
            }
            else if(color[it] == color[curr])
                return true;
        }
        
        return a;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector <int> visited (n+1,0);
        vector <int> color (n+1,-1);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(isNotBipartite(n,i,graph,visited,color))
                    return false;
            }
        }
        
        return true;
    }
};