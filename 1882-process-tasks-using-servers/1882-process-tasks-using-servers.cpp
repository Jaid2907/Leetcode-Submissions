class cmp1{
  public:
    bool operator() (pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

class cmp2{
    public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        
        int n = tasks.size();
        int m = servers.size();
        vector<int> ans(n);
        
        priority_queue<pair<int,int>, vector<pair<int,int>> ,cmp1> free;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2> occupied;
        
        for(int i = 0; i<m; i++){
            free.push({servers[i],i});
        }
        
        int j = 0;
        int curr_time = 0;
        
        while(j<n){
        
            if(free.empty()){
                auto [completion_time, ind] = occupied.top();
                occupied.pop();
                curr_time = completion_time;
                free.push({servers[ind],ind});   
            }
            
             while(!occupied.empty() && occupied.top().first <= curr_time){
                auto [completion_time, ind] = occupied.top();
                occupied.pop();
                free.push({servers[ind],ind});
            }
            auto [weight,ind] = free.top();
            free.pop();
            ans[j] = ind;
            occupied.push({curr_time + tasks[j], ind});
            if(curr_time == j)
            curr_time++;
            j++;
        }
        
        return ans;
        
    }
};