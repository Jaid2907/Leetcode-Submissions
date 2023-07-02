//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU{
	public:
	vector<int> parent;
	vector<int> rank;

	DSU(int n){
		parent.resize(n,-1);
		rank.resize(n,1);
	}

	int find(int num){
		if(parent[num] == -1)
			return num;
		
		return parent[num] = find(parent[num]);
	}


	void union_set(int s1, int s2){
		int x = find(s1);
		int y = find(s2);

		if(x!=y){

			if(rank[x] < rank[y]){
				parent[x] = y;
				rank[y] += rank[x];
			}
			else{
				parent[y] = x;
				rank[x] += rank[y];
			}
		}
	}

	bool sameSet(int x, int y){
		return find(x) == find(y);
	}
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        DSU uf(m*n+1);
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        int ans = 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!grid[i][j])
                    continue;
                ans = max(ans, uf.rank[i*n+j]);
                for(int k = 0; k<4; k++){
                    int x = i + row[k];
                    int y = j + col[k];
                    
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]){
                        uf.union_set(i*n+j,x*n+y);
                        ans = max(ans, uf.rank[i*n+j]);
                        ans = max(ans, uf.rank[x*n+y]);
                    }
                }
            }
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++)
                ans = max(ans, uf.rank[i*n+j]);
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j])
                    continue;
                int curr = 1;
                set<int> s;
                for(int k = 0; k<4; k++){
                    int x = i + row[k];
                    int y = j + col[k];
                    
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]){
                        int id = uf.find(x*n+y);
                        if(s.find(id) == s.end()){
                            curr += uf.rank[id];
                            s.insert(id);
                        }
                    }
                }
                
                ans = max(ans, curr);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends