//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int n = s.size();
        // unordered_map<char,int> mp;
        int freq[26] = {0};
        int j = 0;
        int ans = 0;
        
        
        for(int i = 0; i<n; i++){
           freq[s[i]-'a']++;
            
           
                while(freq[s[i]-'a'] > 1){
                    freq[s[j]-'a']--;
                    j++;
                }
            
            
            ans = max(ans,i-j+1);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends