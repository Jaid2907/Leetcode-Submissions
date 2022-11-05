//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class compare{
  public:
  bool operator()(pair<pair<int,int>,int>& a, pair<pair<int,int>,int>& b){
      return a.second > b.second;
  }
};
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>>, compare> pq;
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        pq.push({{0,0},0});
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int i = node.first.first;
            int j = node.first.second;
            int height = node.second;
            
            for(int k = 0; k<4; k++){
                int x = i + row[k];
                int y = j + col[k];
                
                if(x>=0 && y>=0 && x<m && y<n && (max(abs(heights[i][j] - heights[x][y]),height) < dist[x][y])){
                    dist[x][y] = max(abs(heights[i][j] - heights[x][y]),height);
                    pq.push({{x,y},dist[x][y]});
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends