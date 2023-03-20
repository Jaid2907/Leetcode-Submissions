//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        queue<vector<int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='X'){
                    q.push({i,j,0});
                    grid[i][j]='#';
                }
            }
        }
        
        int ans=INT_MAX;
        vector<pair<int,int>> v={{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            
            auto cur=q.front();
            q.pop();
            int x=cur[0],y=cur[1],steps=cur[2];
            
           
            
            for(int i=0;i<4;i++){
                
                int r=v[i].first+x,c=v[i].second+y;
                if(r<0 or r>=n or c<0 or c>=m or grid[r][c]=='#')continue;
                // if(grid[r][c]=='Y')ans=min(ans,steps+1);
                // else 
                if(grid[r][c]=='Y') return steps+1;
                q.push({r,c,steps+1});
                grid[r][c]='#';
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
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends