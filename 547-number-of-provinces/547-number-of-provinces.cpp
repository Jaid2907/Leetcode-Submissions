class Solution {
public:
    void dfs(vector<int>& visited, vector<vector<int>>& isConnected, int curr)
    {
        visited[curr] = 1;
        int n = isConnected.size();
        for(int i=0; i<n; i++)
        {
            if(isConnected[curr][i] == 1 && visited[i] == 0)
                dfs(visited,isConnected,i);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
     
        int n = isConnected.size();
        vector<int> visited(n,0);
        int cnt = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(visited,isConnected,i);
            }
        }
        
        return cnt;
    }
};