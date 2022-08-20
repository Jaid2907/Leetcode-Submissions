class compare{
  public:
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        
        
        stations.push_back({0,startFuel});
        int n = stations.size();
        sort(stations.begin(), stations.end(),cmp);
        
        int j = 0;
        int curr_pos = 0;
        int cnt = 0;
        
     
        priority_queue <pair<int,int>, vector<pair<int,int>> ,compare> pq;
        while(curr_pos < target){
            
            
            while(j<n && curr_pos - stations[j][0] >= 0){
                pq.push({stations[j][0], stations[j][1]});
                j++;
            }
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            if(pq.empty()){
                return -1;
            }
            curr_pos += pq.top().second;
            pq.pop();
            cnt++;
        }
        
        return cnt-1;
    }
};