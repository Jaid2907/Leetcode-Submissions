//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int cnt = 0;
        int mod = 1e9+7;
        vector<pair<long long int,long long int>> adj[n];
        
        for(int i = 0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<long long int> dist(n,1e18);
        set<pair<long long int,long long int>> s;
        s.insert({0,0});
        dist[0] = 0;
        vector<int> ways(n,0);
        ways[0] = 1;
        
        while(!s.empty()){
            auto node = *s.begin();
            int curr = node.second;
            int dis = node.first;
            s.erase(s.begin());
            
            for(auto &it: adj[curr]){
                if(dis+it.second < dist[it.first]){
                    dist[it.first] = dis + it.second;
                    s.insert({dist[it.first], it.first});
                    ways[it.first] = ways[curr];
                }
                else if(dis+it.second == dist[it.first]){
                    ways[it.first] = (ways[it.first] + ways[curr])%mod;
                }
            }
            
        }
        
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends