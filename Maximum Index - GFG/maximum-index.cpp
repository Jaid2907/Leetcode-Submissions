//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        stack<int> st;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(st.empty() || arr[st.top()] > arr[i]){
                st.push(i);
            }
        }
        
        for(int i = n-1; i>=0; i--){
            
            while(!st.empty() && st.top() > i)
                st.pop();
                
            while(!st.empty() && arr[i] >= arr[st.top()]){
                ans = max(ans, i-st.top());
                st.pop();
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