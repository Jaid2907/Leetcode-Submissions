//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int j = 0;
           int pos = 0, neg = 0;
           int ans = 0;
           int last_neg = -1;
           
           for(int i = 0; i<n; i++){
               if(arr[i] == 0){
                   j = i + 1;
                   neg = 0;
                   last_neg = -1;
                   continue;
               }
               if(arr[i] > 0)
                pos++;
               else{
                   neg++;
                   if(last_neg == -1)
                   last_neg = i;
               }
               
               if(neg%2 == 0){
                   ans = max(ans, i-j+1);
               }
               else if(last_neg >= 0){
                   ans = max(ans, i-last_neg);
               }
           }
           
           
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends