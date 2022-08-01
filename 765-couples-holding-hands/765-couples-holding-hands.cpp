class DSU {
    public:
    vector<int> rank;
    vector<int> parent;
    
    DSU(int n){
        
        rank.resize(n,0);
        parent.resize(n);
        
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        
    }
    void set_parent(int child, int par){
        
        parent[child] = par;
    }
    
    int find(int i){
        
        if(parent[i] == i)
            return i;
        
        return find(parent[i]);
    }
    
    void union_set(int x, int y){
        
        int s1 = find(x);
        int s2 = find(y);
        
        if(s1 != s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    
    bool diff_set(int x, int y){
        
        int s1 = find(x);
        int s2 = find(y);
        
        if(s1 == s2)
            return false;
        parent[s1] = s2;
        
        return true;
    }
    
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU ds(n);
        int cnt = 0;
        
        
        for(int i = 0; i<n; i+=2){
            
            ds.set_parent(row[i], row[i]);
            ds.set_parent(row[i+1], row[i]);
        }
        
        for(int i = 0; i<n; i+=2){
            
            if(ds.diff_set(i,i+1)){
                cnt++;
            }
        }
        
        return cnt;
        
    }
};