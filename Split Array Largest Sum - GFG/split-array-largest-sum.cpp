//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int mid, int nums[], int n, int k){
        
        int i = 0;
        int sum = 0;
        int  cnt = 1;
        while(i<n){
            
            if(nums[i]+sum > mid){
                sum = nums[i];
                cnt++;
            }
            else{
                sum += nums[i];
            }
            i++;
        }
        
        return sum<=mid && cnt <= k;
    }
    int splitArray(int nums[] ,int n, int k) {
        // code here
        int low = *max_element(nums,nums+n), high = 1e9;
        int ans = low;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            bool res = check(mid,nums,n,k);
            
            if(res){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends