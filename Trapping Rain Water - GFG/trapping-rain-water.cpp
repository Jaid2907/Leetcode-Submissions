//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long int ans = 0;
        vector<int> left(n,0), right(n,0);
        int maxi = -1;
        
        
        for(int i = 0; i<n; i++){
           left[i] = maxi;
           maxi = max(maxi, arr[i]);
        }
        maxi = -1;
        for(int i = n-1; i>=0; i--){
            right[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        
        for(int i = 1; i<n-1; i++){
           ans += max(min(left[i], right[i])-arr[i],0);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends