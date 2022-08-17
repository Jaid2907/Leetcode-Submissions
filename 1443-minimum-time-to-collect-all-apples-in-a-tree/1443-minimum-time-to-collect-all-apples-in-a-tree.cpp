class Solution {
public:
    int ans = 0;
    bool dfs (int src, list<int> l[], vector<bool>& hasApple, vector<int>& visited){
        visited[src] = 1;
        bool flag = false;
        
        for(auto it: l[src]){
            if(!visited[it]){
                bool curr = dfs(it,l,hasApple,visited);
                if(curr)
                    ans += 2;
                flag = flag || curr;
            }
        }
        
        return flag || hasApple[src];
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        list<int> l[n];
        
        for(auto &it: edges){
            l[it[0]].push_back(it[1]);
            l[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        for(int i = 0; i<n; i++){
            if(!visited[i]){
               dfs(0,l,hasApple,visited);
            }
        }
        
        
        return ans;
    }
};