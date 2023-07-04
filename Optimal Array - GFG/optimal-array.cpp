//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int> ans(n,0);
        vector<int> prefix(n,0);
        int sum = a[0];
        prefix[0] = sum;
        ans[0] = 0;
        
        for(int i = 1; i<n; i++){
            
            int mid = i/2;
            sum += a[i];
            prefix[i] = sum;
            
            ans[i] += a[mid]*(mid+1) - prefix[mid];
            
            if(i == 1){
                ans[i] += prefix[i]-prefix[mid] - (i-mid)*a[mid] ;
            }
            else{
                ans[i] += prefix[i]-prefix[mid-1] - (i-mid+1)*a[mid];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends