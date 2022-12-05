//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    vector<int> row = {1,-1,0,0};
	    vector<int> col = {0,0,1,-1};
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    
	    queue<vector<int>> q;
	    
	    for(int i = 0; i<m; i++){
	        for(int j = 0; j<n; j++){
	            if(grid[i][j])
	                q.push({i,j,0});
	        }
	    }
	    vector<vector<int>> ans(m, vector<int>(n,0));
	    while(!q.empty()){
	        auto node = q.front();
	        q.pop();
	        
	        for(int k = 0; k<4; k++){
	            int x = node[0] + row[k];
	            int y = node[1] + col[k];
	            
	            if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == 0){
	                grid[x][y] = 1;
	                ans[x][y] = node[2] + 1;
	                q.push({x,y,node[2]+1});
	            }
	        }
	    }
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends