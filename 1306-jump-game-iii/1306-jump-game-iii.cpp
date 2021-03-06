class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n,0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        
        
        while(!q.empty()){
            
            auto node = q.front();
            q.pop();
            
            if(arr[node] == 0)
                return true;
            
            if(node + arr[node] <n && !visited[node + arr[node]]){
                q.push(node + arr[node]);
                visited[node + arr[node]] = 1;
            }
            
            if(node - arr[node] >=0 && !visited[node - arr[node]]){
                q.push(node - arr[node]);
                visited[node - arr[node]] = 1;
            }
        }
        
        return false;
        
    }
};