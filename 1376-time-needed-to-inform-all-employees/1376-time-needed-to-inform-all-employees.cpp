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
    
    void bfs (int source, vector<int>& ans, vector<int>& informTime){
        vector<int> visited(V,0);
        queue<int> q;
        q.push(source);
        ans[source] = 0;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(auto it: l[node]){
                
                if(!visited[it]){
                    visited[it] = 1;
                    ans[it] = ans[node] + informTime[node];
                    q.push(it);
                }
            }
        }
    }
};
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
     
        Graph g(n);
        
        for(int i=0; i<n; i++){
            if(i != headID)
            g.addEdge(i,manager[i]);
        }
        vector<int> ans(n,-1);
        g.bfs(headID, ans, informTime);
        
        return *max_element(ans.begin(),ans.end());
        
    }
};