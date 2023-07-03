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
		parent.resize(n);
		for(int i = 0; i<n; i++)
		    parent[i] = i;
		rank.resize(n,1);
	}

	int find(int num){
		if(parent[num] == num)
			return num;
		
		return parent[num] = find(parent[num]);
	}


	bool union_set(int s1, int s2){
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
			return true;
		}
		else{
		    return false;
		}
	}

	bool sameSet(int x, int y){
		return find(x) == find(y);
	}
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        swap(n,m);
        DSU uf(m*n+1);
        vector<int> res(operators.size());
        int ans = 0;
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        vector<vector<int>> grid(m, vector<int>(n,0));
        
        
        for(int i = 0; i<operators.size(); i++){
            
            int j = operators[i][0];
            int k = operators[i][1];
            
            if(grid[j][k]){
                res[i] = ans;
                continue;
            }
            
            grid[j][k] = 1;
            set<int> s;
            int f = 0;
           
            
            for(int l = 0; l<4; l++){
                int x = j + row[l];
                int y = k + col[l];
                
                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]){
                    
                    if(uf.union_set(j*n+k,x*n+y)){
                        f++;
                    }
                    
                }
            }
            
            
            if(f == 0)
                ans++;
            else
                ans -= f-1;
                
            res[i] = ans;
        }
        
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends