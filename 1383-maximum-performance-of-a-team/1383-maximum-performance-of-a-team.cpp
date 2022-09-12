class compare{
  public:
    bool operator()(pair<long long int,long long int>& a, pair<long long int,long long int>& b){
        return a.first > b.first;
    }
};
class Solution {
public:
    static bool cmp(pair<long long int,long long int>& a, pair<long long int,long long int>& b){
        return a.second > b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long int,long long int>> v(n);
        
        for(int i = 0; i<n; i++){
            v[i] = {speed[i], efficiency[i]};
        }
        
        sort(v.begin(), v.end(), cmp);
        
        priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int>>, compare> pq;
        
        long long int speed_cnt = 0;
        long long int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            pq.push(v[i]);
            speed_cnt += v[i].first;
            
            if(pq.size() > k){
                speed_cnt -= pq.top().first;
                pq.pop();
            }
            
            ans = max(ans, speed_cnt * v[i].second);
        }
        
        int m = 1e9+7;
        return ans%m;
    }
    
};