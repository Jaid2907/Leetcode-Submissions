//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int nums[], int n) 
    { 
        // Your code here
        stack<int> st;
        int ans = 0;
        
        
        for(int i = 0; i<n; i++){
            if(st.empty() || nums[st.top()] > nums[i])
                st.push(i);
        }
        
        
        for(int j = n-1; j>=0; j--){
            
            while(!st.empty() && nums[st.top()] <= nums[j]){
                ans = max(ans, j-st.top());
                st.pop();
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends