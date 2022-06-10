class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(auto it: rooms[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        
        for(auto it: visited){
            if(it == 0)
                return false;
        }
        return true;
        
    }
};