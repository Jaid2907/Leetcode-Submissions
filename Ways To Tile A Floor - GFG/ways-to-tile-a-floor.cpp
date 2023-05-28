//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long numberOfWays(long long n) {
        //code here
        
        if(n == 1)
            return 1;
        
        int prev = 2;
        int secondPrev = 1;
        
        
        int mod = 1e9+7;
        
        for(int i = 3; i<=n; i++){
            int curr = (prev + secondPrev)%mod;
            secondPrev = prev;
            prev = curr;
            
        }
        
        return prev;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends