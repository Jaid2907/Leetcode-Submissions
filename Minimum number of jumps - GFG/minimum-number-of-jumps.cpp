//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(arr[0] == 0)
            return -1;
        int currEnd = 0, jumps = 0, currFarthest = 0;
        
        for(int i = 0; i<n-1; i++){
            currFarthest = max(currFarthest,i+arr[i]);
            
            if(i == currEnd){
                jumps++;
                currEnd = currFarthest;
            }
        }
        
        return currEnd >= n-1 ? jumps : -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends