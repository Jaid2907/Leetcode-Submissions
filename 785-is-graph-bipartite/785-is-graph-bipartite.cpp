class Solution {
public:
    bool isNotBipartite(int curr,vector<vector<int>>& graph, vector<int>& visited, vector<int>& color )
    {
        visited[curr] = 1;
        queue<int> q;
        q.push(curr);
        color[curr] = 1;
        
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            for(auto it: graph[t])
            {
                if(!visited[it])
                {
                    color[it] = !color[t];
                    q.push(it);
                    visited[it] = 1;
                }
                else if(color[it] == color[t])
                    return true;
                    
            }
            
            
        }
        
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector <int> visited (n+1,0);
        vector <int> color (n+1,-1);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(isNotBipartite(i,graph,visited,color))
                    return false;
            }
        }
        
        return true;
    }
};