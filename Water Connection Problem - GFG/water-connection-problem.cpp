//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs (int curr, vector<pair<int,int>> adj[], vector<int>& vis, int& end, int& mini){
        vis[curr] = 1;
        end = curr;
        for(auto &it: adj[curr]){
            if(!vis[it.first]){
                mini = min(mini,it.second);
                dfs(it.first,adj,vis,end,mini);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
       vector<vector<int>> ans;
       vector<pair<int,int>> adj[n+1];
       vector<int> in(n+1,0), out(n+1,0);
       vector<int> vis(n+1,0);
       
       for(int i = 0; i<p; i++){
            adj[a[i]].push_back({b[i],d[i]});
            in[b[i]]++;
            out[a[i]]++;
       }
       
       for(int i = 1; i<=n; i++){
           if(in[i] == 0 && out[i] == 1 && !vis[i]){
               int start = i;
               int end = i;
               int mini = INT_MAX;
               dfs(i,adj,vis,end,mini);
               ans.push_back({start,end,mini});
           }
       }
       
       return ans;
       
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends