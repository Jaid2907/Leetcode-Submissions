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
    static bool compare (pair<int,char>& a, pair<int,char>& b){
        return a.second<b.second;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        DSU dsu(n);
        unordered_map<int,vector<pair<int,char>>> mp;
        for(int i = 0; i<pairs.size(); i++){
            
            dsu.union_set(pairs[i][0],pairs[i][1]);
        }
        
        for(int i  = 0; i<n; i++){
            int parent = dsu.find(i);
            mp[parent].push_back({i,s[i]});
        }
        
        
        string ans(n,'.');
        
        for(auto it: mp){
            
            vector<int> ind;
            for(auto index:it.second){
                ind.push_back(index.first);
            }
            
            sort(it.second.begin(), it.second.end(),compare);
            int j = 0;
            for(auto ch : it.second){
                
                ans[ind[j++]] = ch.second;
            }
        }
        
        
        return ans;
        
    }
};