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
    }
    
    void dfs(int i, vector<int>& visited){
        
        visited[i] = 1;
        
        for(auto it: l[i]){
            if(!visited[it]){
                dfs(it,visited);
            }
        }
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        Graph g(n);
        vector<int> temp(n,0);
        
        for(auto it: edges){
            temp[it[1]]++;
        }
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(temp[i] == 0)
                ans.push_back(i);
        }
        return ans;
        
    }
};