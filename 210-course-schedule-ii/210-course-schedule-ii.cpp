class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        vector<int> ans;
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
        
        //zero Indegree nodes pushed in the queue
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            ans.push_back(node);
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
        {
            ans.clear();
            return ans;
            
            
        }
        
        return ans;
    }
};