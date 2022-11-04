//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int compare (int num, int mid){
        int cnt = 0;
        while(num){
            num /= mid;
            cnt++;
        }
        
        return cnt;
            
    }
    string baseEquiv(int n, int m){
        // code here
        int low = 2, high = 32;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int res = compare(n,mid);
            if(res == m)
                return "Yes";
            if(res > m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        
       
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends