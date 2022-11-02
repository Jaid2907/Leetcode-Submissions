//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& nums, int k){
        //Code here
        long long int n = nums.size();
        long long int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++){
            
            auto ub = upper_bound(nums.begin(), nums.end(), nums[i] + k) - (nums.begin() + i);
            
            ans = min(ans, n - ub);
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends