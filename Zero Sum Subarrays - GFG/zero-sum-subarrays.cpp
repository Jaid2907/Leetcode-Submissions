//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int helper (int l, int r, vector<long long int>& nums){
        long long int ans = 0;
        unordered_map<long long int,long long int> mp;
        mp[0]++;
        long long int sum = 0;
        long long int cnt = 0;
        
        for(int i = l; i<=r; i++){
            sum += nums[i];
            if(mp.find(sum) != mp.end()){
                cnt += mp[sum];
            }
            mp[sum]++;
        }
        
        return cnt;
    }
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        return helper(0,n-1,arr);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends