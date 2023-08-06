//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    int check(int mid, int n, int k, vector<int>& stalls){
        int curr = stalls[0];
        int cnt = 1;
        
        for(int i = 1; i<n; i++){
            if(stalls[i] - curr >= mid){
                cnt++;
                curr = stalls[i];
            }
        }
        
        return cnt >= k;
        
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int low = 1, high = 1e9;
        sort(stalls.begin(), stalls.end());
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int cnt = check(mid,n,k,stalls);
            
            if(cnt){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends