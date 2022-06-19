class Graph{
    public:
    int V;
    list<int>* l;
    
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
     
        Graph g(n);
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(auto it: roads){
            adj[it[0]][it[1]] = 1;
            adj[it[1]][it[0]] = 1;
            g.addEdge(it[0],it[1]);
        }
        
        int ans = 0;
        
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int a = g.l[i].size();
                int b = g.l[j].size();
                
                if(adj[i][j])
                    a--;
                
                ans = max(ans,a+b);
            }
        }
        return ans;
    }
    
};