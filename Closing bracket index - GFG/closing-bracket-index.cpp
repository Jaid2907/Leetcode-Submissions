//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closing (string s, int pos)
        {
        	//code here.
        	int open = 0;
        	int open_store;
        	int  n = s.size();
        	
        	for(int i = 0; i<n; i++){
        	    if(s[i] == '['){
        	    if(i == pos){
        	           open_store = open;
        	        }
        	        open++;
        	    }
        	    else if(s[i] == ']'){
        	        open--;
        	        if(open == open_store)
        	            return i;
        	    }
        	}
        	
        	return 0;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int pos; cin >> pos;
        Solution ob;
		cout <<ob.closing (s, pos) << '\n';
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends