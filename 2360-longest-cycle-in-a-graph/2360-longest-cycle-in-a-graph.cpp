class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0);
        int ans = -1;
        
        for(int i = 0; i<n; i++){
            
            if(visited[i])
                continue;
            
            int idx = i;
            int dist = 0;
            unordered_map<int,int> mp;
            
            while(idx != -1){
                
                if(mp.find(idx) != mp.end()){
                    ans = max(ans, dist - mp[idx]+1);
                    break;
                }
                if(visited[idx])
                    break;
                dist++;
                mp[idx] = dist;
                visited[idx] = 1;
                idx = edges[idx];
            }
            
        }
        
        return ans;
    }
};