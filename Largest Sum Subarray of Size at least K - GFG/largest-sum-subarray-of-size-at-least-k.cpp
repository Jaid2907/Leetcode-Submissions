//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    vector<long long int> prefix(n+1,0);
    long long int sum = 0;
    
    for(int i = 0; i<n; i++){
        sum += a[i];
        prefix[i+1] = sum;
    }
    
    vector<int> dp(n,0);
    sum = 0;
    long long int ans = INT_MIN;
    
    for(int i = 0; i<n; i++){
        sum += a[i];
        if(sum < 0)
            sum = 0;
        dp[i] = sum;
        
        if(i-k >= -1){
            long long int temp = prefix[i+1];
            temp -= i-k+1 >= 0 ? prefix[i-k+1] : 0;
            // if(i == n-1)    
            //     cout<<temp<<endl;
            temp += i-k >=0? dp[i-k] : 0;
            
            ans = max(ans,temp);
        }
        
    }
    
    return ans;
}