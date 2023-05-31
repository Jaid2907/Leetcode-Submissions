//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> nums){
        //code here
        vector<int> suffix(n,-1);
        vector<int> ind(n,-1);
        
        vector<int> ans(n,-1);
        int mini = nums[n-1];
        suffix[n-1] = mini;
        ind[n-1] = n-1;
        
        for(int i = n-2; i>=0; i--){
            
            if(nums[i] <= mini){
                mini = nums[i];
                suffix[i] = mini;
                ind[i] = i;
                ans[i] = -1;
                continue;
            }
            else{
                suffix[i] = suffix[i+1];
                ind[i] = ind[i+1];
            }
             
            
            auto it = lower_bound(suffix.begin()+i+1, suffix.end(), nums[i]);
            if(it == suffix.end() || *it >= nums[i])
                it--;
            
            int index = it-suffix.begin();
            ans[i] = index;
            
          
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}
// } Driver Code Ends