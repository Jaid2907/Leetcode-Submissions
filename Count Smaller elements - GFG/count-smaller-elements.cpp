//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void merge (int low, int mid, int high, vector<pair<int,int>>& vec, vector<int>& ans){
        int size = high-low+1;
        vector<pair<int,int>> temp(size);
        int i = mid, j = high, k = size-1;
        
        while(i>=low && j>mid){
            if(vec[i].first > vec[j].first){
                ans[vec[i].second] += j-mid;
                temp[k--] = vec[i--];
            }
            else{
                temp[k--] = vec[j--];
            }
        }
        
        while(i>=low){
            temp[k--] = vec[i--];
        }
        
        while(j>mid)
            temp[k--] = vec[j--];
        
        k = 0;
        for(int i = low; i<=high; i++){
            vec[i] = temp[k++];
        }
        
        
    }
    void mergeSort(int low, int high, vector<pair<int,int>>& vec, vector<int>& ans){
        if(low >= high)
            return ;
            
        int mid = low + (high-low)/2;
        mergeSort(low,mid,vec,ans);
        mergeSort(mid+1,high,vec,ans);
        merge(low,mid,high,vec,ans);
    }
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<pair<int,int>> vec;
	    
	    for(int i = 0; i<n; i++){
	        vec.push_back({arr[i],i});
	    }   
	    vector<int> ans(n,0);
	    mergeSort(0,n-1,vec,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends