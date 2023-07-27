//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class compare{
    public:
    bool operator()(int a, int b){
        return a > b;
    }
};
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code herei
        int n = num;
        vector<int> ans(n);
        priority_queue<int,vector<int>, compare> pq;
        k++;
        for(int i = 0; i<k; i++)
            pq.push(arr[i]);
        
        int j = 0;
        
        for(int i = k; i<n; i++){
            auto top = pq.top();
            pq.pop();
            ans[j++] = top;
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans[j++] = top;
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