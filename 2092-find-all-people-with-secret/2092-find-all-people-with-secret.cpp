class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n){
        parent.resize(n,-1);
        rank.resize(n,0);
    }
    
    int find(int i){
        if(parent[i] == -1)
            return i;
        
        return parent[i] = find(parent[i]);
    }
    
    void union_set (int i, int j){
        int x = find(i);
        int y = find(j);
        
        if(x != y){
            if(x == 0)
                parent[y] = x;
            else if(y == 0)
                parent[x] = y;
            else
                parent[x] = y;
        }
    }
    void reset(int i){
        parent[i] = -1;
    }
    
    bool connected(int i, int j){
      return  find(i) == find(j);
    }
};
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
      
        return a[2]<b[2];
        
        
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),compare);   
        
        DSU obj(n);
        obj.parent[firstPerson] = 0;
        vector<int> ppl;
        
        for(int i=0; i<meetings.size();){
            
            ppl.clear();
            int time = meetings[i][2];
            
            while(i<meetings.size() && meetings[i][2] == time){
                obj.union_set(meetings[i][0],meetings[i][1]);
                ppl.push_back(meetings[i][0]);
                ppl.push_back(meetings[i][1]);
                i++;
            }
            
            for(auto &it: ppl){
                if(!obj.connected(0,it))
                    obj.reset(it);
                
            }
            
            
        }
        
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(obj.find(i) == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};