class Solution {
public:
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
        
        void dfs(int node, vector<int>& visited){
            visited[node] = 1;
            
            for(auto it: l[node]){
                
                if(!visited[it]){
                    dfs(it,visited);
                }
            }
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
     
        if (connections.size()<n-1)
            return -1;
        
        Graph g(n);
        
        for(auto it: connections){
            g.addEdge(it[0],it[1]);
        }
        int cnt_components = 0;
        vector<int> visited(n,0);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                g.dfs(i,visited);
                cnt_components++;
            }
        }
        
        
        return cnt_components-1;
        
        
    }
};