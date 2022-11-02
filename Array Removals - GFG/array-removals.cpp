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
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = n-1; i>=0; i--){
            int j = 0;
            
            while(j < i && nums[i] - nums[j] > k)
                j++;
            
            ans = min(ans, j + n-i - 1);
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