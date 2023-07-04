//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        set<int> s;
        int n = num;
        vector<int> ans;
        
        for(int i = 0; i<=k; i++){
            s.insert(arr[i]);
        }
        ans.push_back(*s.begin());
        s.erase(s.begin());
        for(int i = k+1; i<n; i++){
            s.insert(arr[i]);
            auto top = *s.begin();
            s.erase(s.begin());
            ans.push_back(top);
        }
        
        while(!s.empty()){
            ans.push_back(*s.begin());
            s.erase(s.begin());
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends