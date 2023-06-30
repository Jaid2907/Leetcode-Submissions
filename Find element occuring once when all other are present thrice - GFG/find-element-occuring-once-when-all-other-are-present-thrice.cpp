//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int n) {
        // code here
        int num = 0;
        int cnt = 0;
        
        for(int j = 0; j<32; j++){
            int curr_mask = (1<<j);
            cnt = 0;
            
            for(int i = 0; i<n; i++){
                
                if(arr[i]&curr_mask)
                    cnt++;
            }
            
            if(cnt%3 != 0)
                num = (num | curr_mask);
        }
        
        
        
        return num;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends