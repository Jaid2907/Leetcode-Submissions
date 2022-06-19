class Graph{
    public:
    int V;
    list<pair<int,int>>* l;
    
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>>[V];
    }
    
    void addEdge (int u, int v, int color){
        l[u].push_back({v,color});
    }
    
};
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //Color 0 for red and 1 for blue
        Graph g(n);
        // unordered_map<int,pair<int,int>> mp;
        vector<vector<int>> visited (n,vector<int>(2,0));
        for(auto it: redEdges){
            g.addEdge(it[0],it[1],0);
        }
        for(auto it: blueEdges){
            g.addEdge(it[0],it[1],1);
        }
        
        vector<int> dist (n, INT_MAX-1e5);
        dist[0] = 0;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        visited[0] = {1,1};
        int cnt =0;
        
        
        while(!q.empty()){
            
            int size = q.size(); 
            if(size)
                cnt++;
            while(size--){
                
            auto [node,color] = q.front();
            
            q.pop();
            
            for(auto it: g.l[node]){
                
                if(it.second == 1-color && !visited[it.first][it.second]){
                    
                    visited[it.first][it.second] = 1;
                    q.push({it.first,it.second});
                    if(dist[it.first]>cnt)
                    dist[it.first] = cnt;
                }
                
            }
            
            }
            
            
        }
        
        for(int i=0; i<n; i++){
            if(dist[i] == INT_MAX-1e5)
                dist[i] = -1;
        }
        return dist;
        
        
    }
};