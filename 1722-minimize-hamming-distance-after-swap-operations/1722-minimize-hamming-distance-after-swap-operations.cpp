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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        
        DSU dsu(n);
        
        for(int i = 0; i<allowedSwaps.size(); i++){
            dsu.union_set(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        
        unordered_map<int,vector<int>> mp;
        
        for(int i = 0; i<n; i++){
            mp[dsu.find(i)].push_back(i);
        }
        
        int ans = 0;
        
        
        for(auto it: mp){
            
            unordered_map<int,int> m;
            for(auto ele:it.second){
                m[source[ele]]++;
            }
            
            for(auto ele : it.second){
                if(m.find(target[ele]) == m.end()){
                    ans++;
                }
                else{
                    m[target[ele]]--;
                    
                    if(m[target[ele]] == 0)
                        m.erase(target[ele]);
                }
            }
            
        }
        
        return ans;
        
    }
};