//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        queue<pair<pair<int,int>,int>> q;
        q.push({source,0});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node.first == destination)
                return node.second;
            
            for(int k = 0; k<4; k++){
                int x = node.first.first + row[k];
                int y = node.first.second + col[k];
                
                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]){
                    grid[x][y] = 0;
                    q.push({{x,y},node.second+1});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends