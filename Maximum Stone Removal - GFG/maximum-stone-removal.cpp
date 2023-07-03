//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        DSU uf(n);
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    uf.union_set(i,j);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            if(uf.parent[i] == -1)
                ans += uf.rank[i]-1;
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
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends