//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++)
            mp[arr[i]]++;
        
        vector<pair<int,int>> vec;
        
        for(auto &it: mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(), vec.end(), compare);
        vector<int> ans;
        
        for(int i = 0; i<vec.size(); i++){
            for(int j = 0; j<vec[i].first; j++)
                ans.push_back(vec[i].second);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends