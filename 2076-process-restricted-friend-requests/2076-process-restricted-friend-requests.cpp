class DSU {
    public:
    vector<int> parent,rank;
    
    DSU(int n){
        parent.resize(n,0);
        for(int i = 0; i<n; i++)
            parent[i] = i;
        rank.resize(n,0);
    }
    
    int find (int i){
        if(parent[i] == i)
            return i;
        
        return parent[i] = find(parent[i]);
    }
    
    void union_set (int i, int j){
        int x = i, y = j;
        if(x != y){
            
            if(rank[x] < rank[y]){
                parent[x] = y;
                rank[y] += rank[x];
            }
            else{
                parent[y] = x;
                rank[x] += rank[y];
            }
        }
    }
    
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        DSU dsu(n);
        vector<bool> ans(requests.size());
        
        for(int i = 0; i<requests.size(); i++){
            
            int from = requests[i][0];
            int to = requests[i][1];
            int parent_from = dsu.find(from);
            int parent_to = dsu.find(to);
            
            
            int flag = 0;
            if(parent_from != parent_to)
            for(int j = 0; j<restrictions.size(); j++){
                int a = dsu.find(restrictions[j][0]);
                int b = dsu.find(restrictions[j][1]);
                
                 
                if((parent_from == a && parent_to == b) || (parent_from == b && parent_to == a)){
                   flag = 1;
                    break;
                }
            }
            
            if(flag){
                ans[i] = false;
                
            }
            else{
                ans[i] = true;
                dsu.union_set(parent_from,parent_to);
            }
                
            
        }
        
        return ans;
        
    }
};