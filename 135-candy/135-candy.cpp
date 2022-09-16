class graph {
    public:
    list<int>* l;
    int v;
    
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    
    void addEdge(int u, int v){
        l[u].push_back(v);
    }
};
class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        graph g(n);
        vector<int> indegree(n,0);
        
        for(int i = 0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                g.addEdge(i,i+1);
                indegree[i+1]++;
            }
            else if(nums[i] > nums[i+1]){
                g.addEdge(i+1,i);
                indegree[i]++;
            }
        }
        
        queue<pair<int,int>> q;
        vector<int> visited(n,0);
        
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push({i,1});
                visited[i] = 1;
            }
        }
        
        
        int ans = 0;
        
        while(!q.empty()){
            auto [ind,cnt] = q.front();
            ans += cnt;
            q.pop();
            
            for(auto it: g.l[ind]){
                indegree[it]--;
                if(indegree[it] == 0 && !visited[it]){
                    q.push({it,cnt+1});
                    visited[it] = 1;
                }
            }
        }
        
        return ans;
        
        
    }
};