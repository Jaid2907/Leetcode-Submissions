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
        int x = find(i);
        int y = find(j);
        
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
    static bool cmp(string& a, string& b){
        
        return a[1]>b[1];
    }
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        
        sort(equations.begin(), equations.end(),cmp);
        for(int i = 0; i<equations.size(); i++){
            
            int first = equations[i][0]-97;
            int second = equations[i][3]-97;
            int pfirst = dsu.find(first);
            int psecond = dsu.find(second);
            
            if(equations[i][1] == '='){
                 dsu.union_set(pfirst,psecond);
            }
            else{
                
                if(pfirst == psecond)
                    return false;
            }
        }
        
        return true;
    }
};