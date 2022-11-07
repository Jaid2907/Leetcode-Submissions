//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool checker(long long int mid, int nums[], int m, int n){
        int cnt = 1;
        long long int s = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] > mid)
                return false;
        }
        
        int i = 0;
        
        while(i<n){
            
            if(s+nums[i] <= mid){
                s += nums[i];
            }
            else{
                s = nums[i];
                cnt++;
            }
            
            i++;
        }
       
        
        return cnt <= m;
    }
    int findPages(int nums[], int n, int m) 
    {
        int mini = INT_MIN;
        long long int s = 0;
        if(m > n)
            return -1;
        for(int i = 0; i<n; i++){
            mini = max(mini,nums[i]);
            s+=nums[i];
        }
        
        long long int low = mini, high = s, mid;
        
        while(high - low > 1){
            mid = low + (high - low)/2;
            
            if(checker(mid,nums,m,n)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        if(checker(low,nums,m,n)){
            return low;
        }
        else if(checker(high,nums,m,n))
            return high;
        return  -1 ;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends