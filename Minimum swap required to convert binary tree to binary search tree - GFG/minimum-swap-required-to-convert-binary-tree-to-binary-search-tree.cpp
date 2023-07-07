//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    int minSwaps(vector<int>&arr, int n){
        //Write your code here
        stack<int> st;
        st.push(0);
        int curr = 0;
        vector<pair<int,int>> ans;
        
        while(true){
            
            if(2*curr+1 < n){
                st.push(2*curr+1);
                curr = 2*curr+1;
            }
            else{
                auto top = st.top();
                ans.push_back({arr[top],top});
                st.pop();
                int par = (top-1)/2;
                if(2*top+2 < n){
                    st.push(2*top+2);
                    curr = 2*top+2;
                }
                
                if(st.empty())
                    break;
            }
        }
        
      
        
        vector<int> vis(n,0);
        vector<pair<int,int>> sorted = ans;
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++)
            mp[sorted[i].first] = i;
        
        int swaps = 0;
        
        
        for(int i = 0; i<n; i++){
            
            int cnt = 0;
            int curr = i;
            
            while(true){
                if(vis[curr])
                    break;
                vis[curr] = 1;
                curr = mp[ans[curr].first];
                cnt++;
            }
            
            
            if(cnt > 0)
            swaps += cnt-1;
            
        }
        
        return swaps;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends