// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class compare{
  public:
bool operator()(pair<int,pair<int,int>>& p1, pair<int,pair<int,int>>& p2){
  return p1.first>p2.first;
}
};

class Solution
{
    public:
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> row = {0,0,-1,1};
        vector<int> col = {1,-1,0,0};

        vector<vector<int>> dist(n, vector<int> (n,1E9));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});

        while (!pq.empty())
        {
        auto node = pq.top();
        int i = node.second.first;
        int j = node.second.second;
        int dist_of_node = node.first; 
    
        pq.pop();


        for(int k=0; k<4; k++)
        {
        int r = row[k];
        int c = col[k];

        if((r+i)<n && (r+i)>=0 && (c+j)<n && (c+j)>=0){
            if(dist_of_node + grid[i+r][c+j] < dist[r+i][c+j]){
                dist[i+r][c+j] = dist_of_node + grid[i+r][c+j];
                pq.push({dist[i+r][c+j],{i+r,c+j}});
            
                if(i+r == n-1 && j+c == n-1)
                    return dist[n-1][n-1];
          }
        }
    }
    
    
    
  }
  
  
  return dist[n-1][n-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends