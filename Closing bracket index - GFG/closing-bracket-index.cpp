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
        	stack<char> st;
        	int  n = s.size();
        	
        	for(int i = 0; i<n; i++){
        	    if(i == pos){
        	        st.push('*');
        	    }
        	    else if(s[i] == '['){
        	        st.push(s[i]);
        	    }
        	    else if(s[i] == ']'){
        	        if(st.top() == '*')
        	            return i;
        	       st.pop();
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