//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
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
	int count(){
	    int cnt = 0;
	    
	    for(int i = 0; i<parent.size(); i++)
	        if(parent[i] == i)  
	            cnt++;
	   return cnt;
	}
	
	void helper(vector<vector<string>> &accounts, map<int,set<string>>& res){
	    int n = accounts.size();
	    for(int i = 0; i<n; i++)
	        find(i);
	    for(int i = 0; i<n; i++){
	        for(int j = 1; j<accounts[i].size(); j++){
	            res[parent[i]].insert(accounts[i][j]);
	        }
	    }
	    
	}
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
        DSU uf(n);
        map<string,int> mp;
        map<int,set<string>> res;
        
        for(int i = 0; i<accounts.size(); i++){
            string name = accounts[i][0];
            
            for(int j = 1; j<accounts[i].size(); j++){
                
                if(mp.find(accounts[i][j]) != mp.end()){
                    uf.union_set(i,mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]] = i;
                }
            }
        }
        
        uf.helper(accounts,res);
        
        vector<vector<string>> ans;
        
        for(auto &it: res){
            int ind = it.first;
            vector<string> temp;
            temp.push_back(accounts[ind][0]);
            
            for(auto curr: it.second){
                temp.push_back(curr);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
        
        
    }
    
    
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends