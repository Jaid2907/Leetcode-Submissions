// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs( int curr, int parent, vector<int>& visited,vector<int> adj[])
    {
        queue <pair<int,int>> q;
        q.push({curr,parent});
        visited[curr] = 1;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            for(auto it: adj[t.first])
            {
                if(!visited[it])
                {
                    q.push({it,t.first});
                    visited[it] = 1;
                }
                else if(it != t.second)
                return true;
            }
            
            
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<pair<int,int>> q;
        vector<int> visited(V+1,0);
        
        for(int i = 0; i<V; i++)
        {
            if(!visited[i])
            {
                if(bfs(i, -1, visited,adj))
                return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends