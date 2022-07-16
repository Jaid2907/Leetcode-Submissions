class compare {
    public:
  bool operator ()(vector<float>& a, vector<float>& b){
      return a[0]>b[0];
  }  
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<float> , vector<vector<float>>, compare> pq;
        
        for(int i=0; i<points.size(); i++){
            
            float dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            float x = points[i][0];
            float y = points[i][1];
            
            pq.push({dist,x,y});
        }
        vector<vector<int>> ans;
        
        while(k--){
            
            auto it = pq.top();
            pq.pop();
            
            int x = int(it[1]);
            int y = int(it[2]);
            ans.push_back({x,y});
        }
        
        return ans;
    }
};