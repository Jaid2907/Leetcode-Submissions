//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU{
public:
  vector<int> parent;
  vector<int> rank;
  int n;
  
  DSU(int n){
    this->n = n;
    parent.resize(n,-1);
    rank.resize(n,1);
  }
  
  int find(int num){
      if(parent[num] == -1)
        return num;
        
        
      return parent[num] = find(parent[num]);
  }
  
  void union_set(int n1, int n2){
      int x = find(n1);
      int y = find(n2);
      
      if(x!=y){
          if(rank[x] < rank[y]){
              parent[x] = y;
              rank[y] += rank[x];
          }
          else{
              parent[y] = x;
              rank[x] += rank[y];
          }
      }
  }
  
  bool sameSet(int u, int v){
      return find(u) == find(v);
  }
  
  int numberOfComponents(){
      int cnt = 0;
      for(int i = 0; i<n; i++)
        if(parent[i] == -1)
            cnt++;
            
      return cnt;
  }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DSU uf(n);
        int cnt = 0;
        
        for(int i = 0; i<edge.size(); i++){
            int u = edge[i][0];
            int v = edge[i][1];
            
            if(!uf.sameSet(u,v)){
                uf.union_set(u,v);
            }
            else{
                cnt++;
            }
        }
        
        int components = uf.numberOfComponents();
        
        if(components-1 > cnt)
            return -1;
        return components-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends