class Solution {
public:
    bool bfshelper(int source, vector<int>& visited, vector<int>& parent, vector<vector<int>>& graph)
    {
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        parent[source] = source;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(int i=0; i<1001; i++)
            {
                if(graph[node][i] == 1)
                {
                    if(!visited[i])
                    {
                        visited[i] = 1;
                        q.push(i);
                        parent[i] = node;
                    }
                    else if(i != parent[node])
                        return true;
                }
            }
        }
        
        return false;
        
    }
    bool hasCycle(vector<vector<int>>& graph){
        vector<int> visited(1001,0);
        vector<int> parent (1001,-1);
        bool ans = false;
        
        for(int i=0; i<1001; i++)
        {   
            if(!visited[i])
                ans = ans || bfshelper(i,visited,parent,graph);
        }
        
        return ans;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(1001,vector<int>(1001,0));
        
        int i = 0;
        while(i<edges.size()){
            graph[edges[i][0]][edges[i][1]] = 1;
            graph[edges[i][1]][edges[i][0]] = 1;
            i++;
        }
        
        int n = edges.size();
        
        for(int i=n-1; i>=0; i--)
        {
            graph[edges[i][0]][edges[i][1]] = 0;
            graph[edges[i][1]][edges[i][0]] = 0;
            
            if(!hasCycle(graph)){
                vector<int> ans = {edges[i][0], edges[i][1]};
                return ans;
            }
            
            graph[edges[i][0]][edges[i][1]] = 1;
            graph[edges[i][1]][edges[i][0]] = 1;
            
            
        }
        
        vector<int> temp(2,0);
        return temp;
        
    }
};