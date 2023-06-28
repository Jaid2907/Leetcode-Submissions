//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs (int curr, vector<pair<int,int>> adj[], vector<int>& vis, stack<int>& topo){
        vis[curr] = 1;
        
        for(auto &it: adj[curr]){
            if(!vis[it.first])
                dfs(it.first,adj,vis,topo);
        }
        
        topo.push(curr);
    }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int> vis(n,0);
        vector<pair<int,int>> adj[n];
        stack<int> st;
        
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        for(int i = 0; i<n; i++){
            if(!vis[i])
                dfs(i,adj,vis,st);
        }
        
        while(!st.empty() && st.top() != 0)
            st.pop();
            
        vector<int> dist(n,1e9);
        dist[0] = 0;
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            
            for(auto &it: adj[curr]){
                if(dist[curr] + it.second  < dist[it.first])
                 dist[it.first] = dist[curr] + it.second;
            }
        }
        
        for(int i = 0; i<n; i++)
            if(dist[i] == 1e9)
                dist[i] = -1;
        
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends