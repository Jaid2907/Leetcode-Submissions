//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class compare{
    public:
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first;
    }
};
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int,int>> adj[n];
        
        for(int i = 0; i<flights.size(); i++){
            int u = flights[i][0]-1;
            int v = flights[i][1]-1;
            int wt = flights[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        
        
        vector<int> dist(n,1e9);
        dist[k-1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        pq.push({0,k-1});
        
        while(!pq.empty()){
            
            auto node = pq.top();
            pq.pop();
            int curr = node.second;
            int dis = node.first;
            
            for(auto &it: adj[curr]){
                
                if(dis+it.second < dist[it.first]){
                    dist[it.first] = dis + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
            
        }
        
        for(int i = 0; i<n; i++)
            if(dist[i] == 1e9)
                return -1;
            
        return *max_element(dist.begin(), dist.end());
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends