//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_map<int,int> mp;
      int ans = 0;
      for(int i = 0; i<n; i++)
        mp[arr[i]]++;
        
      for(int i = 0; i<n; i++){
          if(mp.find(arr[i]-1) != mp.end())
            continue;
            
            int curr = arr[i];
            int cnt = 0;
            
            while(mp.find(curr) != mp.end()){
                cnt++;
                curr++;
            }
            
            ans = max(ans, cnt);
      }
      
      return ans;
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends