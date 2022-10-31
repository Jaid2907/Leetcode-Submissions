//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int nums[], int n) {
        unordered_map<int,pair<int,int>> mp;
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                
                if(mp.find(nums[i]+nums[j]) != mp.end()){
                    int k = mp[nums[i]+nums[j]].first;
                    int l = mp[nums[i]+nums[j]].second;
                    
                    if(i!=k && i!=l && j!=k && j!=l){
                        vector<int> temp = {k,l,i,j};
                        if(temp < ans || ans.empty())
                            ans = temp;
                    }
                }
                else
                mp[nums[i]+nums[j]] = {i,j};
            }
        }
        
        if(ans.empty())
            return {-1,-1,-1,-1};
        
        return ans;
       
    }
};
    


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends