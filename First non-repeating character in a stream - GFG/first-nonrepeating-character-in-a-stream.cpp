// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> freq(26,0);
		    string str = "";
		    int flag = 0;
		    
		    queue<char> q;
		    
		    for(int i=0;i<A.size(); i++){
		        
		        freq[A[i]-97]++;
		        if(freq[A[i]-97] == 1){
		            q.push(A[i]);
		        }
		        
		        while(!q.empty() && freq[q.front()-97]>1){
		            q.pop();
		        } 
		        
		        if(!q.empty()){
		            str += q.front();
		        }
		        else
		            str += "#";
		    }
		    
		
        return str;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends