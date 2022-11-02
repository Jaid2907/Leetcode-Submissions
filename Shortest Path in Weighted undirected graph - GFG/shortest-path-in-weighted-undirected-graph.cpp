//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class compare{
  public:
  bool operator()(pair<int,int>& a, pair<int,int>& b){
      return a.second > b.second;
  }
};
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> ans;
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1,-1);
        dist[1] = 0;
        vector<pair<int,int>> adj[n+1];
        
        for(int i = 0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        pq.push({1,0});
        
        while(!pq.empty()){
            
            auto node = pq.top();
            pq.pop();
            
            for(auto it: adj[node.first]){
                
                if(dist[node.first] + it.second < dist[it.first]){
                    
                    dist[it.first] = dist[node.first] + it.second;
                    pq.push({it.first, dist[it.first]});
                    parent[it.first] = node.first;
                }
            }
        }
        
        if(dist[n] == INT_MAX)
            return {-1};
        int j = n;
        
        while(parent[j] != -1){
            ans.push_back(j);
            j = parent[j];
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