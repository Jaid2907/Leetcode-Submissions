//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int> prefix;
        int mini = arr[0];
        prefix.push_back(arr[0]);
        int maxi = 0;
        
        for(int i = 1; i<n; i++){
            
            int low = 0, high = prefix.size()-1;
            int ans = -1;
            
            while(low <= high){
                int mid = low + (high-low)/2;
                
                if(prefix[mid] <= arr[i]){
                    ans = mid;
                    high = mid - 1;
                }
                else{
                    low = mid+1;
                }
            }
            
            if(ans != -1)
                maxi = max(maxi,i-ans);
            mini = min(mini,arr[i]);
            prefix.push_back(mini);
        }
        
        return maxi;
        
        
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends