//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int nums[], int n) {
        // code here
        vector<int> temp;
        
        for(int i = 0; i<n; i++){
            if(temp.empty() || nums[i] > temp.back())
                temp.push_back(nums[i]);
            else{
                auto it = lower_bound(temp.begin(), temp.end() , nums[i]);
                if(it != temp.end()){
                    *it = nums[i];
                }
            }
        }
        
        return n-temp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends