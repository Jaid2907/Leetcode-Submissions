//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class compare{
  public:
  bool operator()(vector<int>& a, vector<int>& b){
      return a[0] > b[0];
  }
};
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        
        for(int i = 0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        pq.push({0,src,0});
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int u = node[1];
            int wt = node[2];
            int curr_k = node[0];
            if(curr_k > k)
            continue;
            for(auto it: adj[u]){
                
                if(curr_k <=k && wt + it.second < dist[it.first]){
                    dist[it.first] = wt + it.second;
                    pq.push({curr_k+1,it.first,dist[it.first]});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
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