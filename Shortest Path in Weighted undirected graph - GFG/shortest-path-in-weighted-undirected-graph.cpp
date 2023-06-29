//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> parent(n+1,-1);
        vector<pair<int,int>> adj[n+1];
        
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        set<pair<int,int>> s;
        vector<int> dist(n+1,1e9);
        dist[1] = 0;
        s.insert({0,1});
        
        while(!s.empty()){
            
            auto it = *s.begin();
            int node = it.second;
            int dis = it.first;
            s.erase(s.begin());
            
            for(auto &it: adj[node]){
                
                if(it.second + dis < dist[it.first]){
                    parent[it.first] = node;
                    s.erase({dist[it.first],it.first});
                    dist[it.first] = it.second + dis;
                    s.insert({dist[it.first],it.first});
                }
            }
        }
        
        vector<int> ans;
        while(parent[n] != -1){
            ans.push_back(n);
            n = parent[n];
        }
        
        if(ans.empty()){
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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