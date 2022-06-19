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
        
        for(auto it: roads){
            g.addEdge(it[0],it[1]);
        }
        
        int ans = 0;
        
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int a = g.l[i].size();
                int b = g.l[j].size();
                
                if(find(g.l[i].begin(), g.l[i].end(), j) != g.l[i].end())
                    a--;
                
                ans = max(ans,a+b);
            }
        }
        return ans;
    }
    
};