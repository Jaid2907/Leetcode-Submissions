//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs (int curr, vector<int> adj[], vector<int>& vis, vector<int>& topo){
        vis[curr] = 1;
        
        
        for(auto &it: adj[curr]){
            if(!vis[it])
                dfs(it,adj,vis,topo);
        }
        
        
        topo.push_back(curr);
    }
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int> adj[k];
        
        for(int i = 0; i<n-1; i++){
            string curr = dict[i];
            string temp = dict[i+1];
            
                int l = 0, m = 0;
                while(l<curr.size() && m < temp.size()){
                    if(curr[l] == temp[m]){
                        l++;
                        m++;
                    }
                    else{
                        break;
                    }
                }
                
                if(l<curr.size() && m<curr.size())
                    adj[curr[l]-97].push_back(temp[m]-97);
            
        }
        
        vector<int> vis(k,0), topo;
        string ans = "";
        for(int i = 0; i<k; i++){
            if(!vis[i])
                dfs(i,adj,vis,topo);
        }
        
        for(int i = 0; i<topo.size(); i++){
            ans += (topo[i]+97);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
        
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends