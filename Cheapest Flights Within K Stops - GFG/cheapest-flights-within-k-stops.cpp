//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto &it: flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        queue<vector<int>> q;
        //{src,dist,stops}
        q.push({src,0,0});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int curr = node[0];
            int dis = node[1];
            int stops = node[2];
            
            for(auto &it: adj[curr]){
                
                if(it.second + dis < dist[it.first] && stops+1 <= K+1){
                    dist[it.first] = it.second + dis;
                    q.push({it.first,dist[it.first],stops+1});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends