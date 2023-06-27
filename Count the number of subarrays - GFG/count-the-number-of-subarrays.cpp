//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long int helper(int n, vector<int>& nums, long long int maxi){
        long long int sum = 0;
        long long int ans = 0;
        int j = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            
            while(sum > maxi){
                sum -= nums[j++];
            }
            
            ans += i-j+1;
        }
        
        return ans;
    }
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        // code here
        
        return helper(N,A,R) - helper(N,A,L-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends