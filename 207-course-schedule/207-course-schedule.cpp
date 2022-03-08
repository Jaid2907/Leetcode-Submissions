class Solution {
public:
  
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        queue<int> q;
        //Graph making
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        //indegree updation
        for(auto &i: adj)
        {
            for(auto &j: i)
            indegree[j]++;
        }
        
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        if(q.empty())
            return false;
        
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto &it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
            
        }
        
        if(cnt != numCourses)
            return false;
        return true;
        
    }
};