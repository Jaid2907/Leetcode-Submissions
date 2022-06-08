class Graph{
  public: 
    int V;
    list<pair<int,int>>* l;
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>>[V+1];
    }
    
    void addEdge(int u, int v){
        l[u].push_back({v,0});
        l[v].push_back({u,0});
    }
    
    void bfs(int source, vector<int>& visited, vector<int>& ans){
        
        int k = 0;
        ans[source-1] = 0;
        visited[source] = 1;
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
           
            
            for(auto it: l[node]){
                
                if(!visited[it.first]){
                    visited[it.first] = 1;
                    
                    vector<int> temp(4,-1);
                    
                    for(auto ptr: l[it.first]){
                        if(ans[ptr.first-1] != -1)
                        temp[ans[ptr.first-1]]++;
                    }
                    
                    for(int i=0; i<4; i++){
                        if(temp[i] == -1)
                        {       ans[it.first-1] = i;
                                break;
                        }
                    }
                    
                    q.push(it.first);
                }
                
            }
        }
       
        
        
        
    }
    
    
};
class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        Graph g(n);
        for(auto it: paths){
            g.addEdge(it[0],it[1]);
        }
        vector<int> ans(n,-1);
        vector<int> visited(n+1,0);
        
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                g.bfs(i,visited,ans);
            }
        }
        
        for(int i=0; i<ans.size(); i++)
            ans[i] += 1;
        
       return ans;
        
    }
};