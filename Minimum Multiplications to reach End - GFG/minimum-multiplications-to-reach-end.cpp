//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        queue<pair<int,int>> q;
        q.push({start,0});
        int mod = 1e5;
        vector<int> vis(1e5+1,0);
        vis[start] = 1;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int num = curr.first;
            int steps = curr.second;
    
            for(int i = 0; i<n; i++){
                if(!vis[(num*1ll*arr[i])%mod]){
                    q.push({(num*1ll*arr[i])%mod, steps+1});
                    vis[(num*1ll*arr[i])%mod] = 1;
                    if((num*1ll*arr[i])%mod == end)
                        return steps+1;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends