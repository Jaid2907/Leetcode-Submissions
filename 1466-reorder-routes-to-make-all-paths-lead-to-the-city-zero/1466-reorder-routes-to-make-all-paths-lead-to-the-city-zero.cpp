class Graph{
    public:
    int V;
    list<pair<int,int>>* l;
    
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>>[V];
    }
    
    void addEdge(int u, int v){
        l[u].push_back({v,0});
        l[v].push_back({u,1});
    }
    
    void dfs (int node, vector<int>& visited, int& ans){
        
        visited[node] = 1;
        
        for(auto it: l[node]){
            
            if(!visited[it.first]){
                if(it.second == 0){
                    ans++;
                }
                    
                dfs(it.first,visited,ans);
            }
        }
        
    }
};
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        Graph g(n);
        
        for(auto it: connections){
            g.addEdge(it[0],it[1]);
        }
        int ans = 0;
        vector<int> visited(n,0);
        g.dfs(0,visited,ans);
        
       
        return ans;
        
    }
};