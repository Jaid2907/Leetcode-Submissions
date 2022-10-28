//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int ans = INT_MAX;
        int c = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] <= k)
                c++;
        }
        int curr = 0;
        for(int i = 0; i<c; i++){
            if(arr[i] <= k){
                curr++;
            }
        }
        
        ans = min(ans, c-curr);
        
        for(int i = c; i<n; i++){
            
            if(arr[i-c] <= k )
                curr--;
            
            if(arr[i] <= k)
                curr++;
            ans = min(ans, c-curr);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends