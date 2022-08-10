class cmp{
  public:
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first<b.first;
    }
};
class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[1] == b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
           
        sort(courses.begin(), courses.end(),compare);
        priority_queue< pair<int,int>, vector<pair<int,int>>, cmp> pq;
        
        int maxTime = 0;
        int n = courses.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            
            if(courses[i][0] + maxTime <= courses[i][1]){
                maxTime += courses[i][0];
                pq.push({courses[i][0],courses[i][1]});
                cnt++;
            }
            else{
                if(pq.size() &&  pq.top().first > courses[i][0]){
                    maxTime -= pq.top().first;
                    pq.pop();
                    maxTime += courses[i][0];
                    pq.push({courses[i][0],courses[i][1]});
                }
            }
        }
        return pq.size();
    }
};