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
    
    bool dfs(int i, vector<int>& visited, int color){
        
        visited[i] = color;
        
        for(auto it: l[i]){
            if(visited[it] == 0){
                dfs(it,visited,3-color);
            }
            else if(visited[it] == color)
                return false;
        }
        return true;
    }
};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        Graph g(n);
        
        for(auto it: dislikes){
            g.addEdge(it[0]-1, it[1]-1);
        }
        vector<int> visited(n,0);
        bool ans = true;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans = ans && g.dfs(i,visited,1);
            }
        }
        
        return ans;
        
    }
};