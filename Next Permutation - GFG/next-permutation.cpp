//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> nums){
        int i = n-2;
        
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return nums;
        }
        
        int j = n-1;
        
        while(j > i && nums[j] <= nums[i]){
            j--;
        }
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return nums;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends