class compare{
    public:
  bool operator()(pair<int,int> p1, pair<int,int> p2){
      return p1.second>p2.second;
  }  
};
class Solution {
public:
    //Kind of single source shortest path from node k to all nodes
    // We can use shortest path algorithm for DAG using Toposort and then iterating over it
    class Graph{
      public:
        int V;
        list<pair<int,int>>* l;
        
        Graph(int V){
            this->V = V;
            l = new list<pair<int,int>> [V+1];
        }
        
        void addEdge(int u, int v, int wt){
            l[u].push_back({v,wt});
        }
        
        int Dijkstra (int source){
            
            vector<int> dist(V+1,100001);
            dist[source] = 0;
            dist[0] = -1;
            priority_queue <pair<int,int>, vector<pair<int,int>>, compare> pq;
            pq.push({source,0});
            
            while(!pq.empty()){
                auto node = pq.top();
                pq.pop();
                
                for(auto it: l[node.first]){
                    if(dist[node.first] + it.second < dist[it.first]){
                        dist[it.first] = dist[node.first] + it.second;
                        pq.push({it.first,dist[it.first]});
                    }
                }
                
            }
            
            int ans = *max_element(dist.begin(),dist.end());
            if(ans == 100001)
                return -1;
            return ans;
            
            
        }
        
       
        
        
        
        
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        Graph g(n);
        
        for(auto it: times){
            g.addEdge(it[0],it[1],it[2]);
        }
        
        return g.Dijkstra(k);
       
        
        
    }
};