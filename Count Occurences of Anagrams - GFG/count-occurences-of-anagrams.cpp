// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool isAnagram(int freq[], int freq2[])
    {
        for(int i=0; i<26; i++)
        {
            if(freq[i] != freq2[i])
            return false;
        }
        
        return true;
    }
	int search(string pat, string txt) {
	    // code here
	    int freq[26] = {0};
	    int freq2[26] = {0};
	    int k = pat.size();
	    int n = txt.size();
	    for(int i=0; i<k; i++)
	    {
	        freq[txt[i]-97]++;
	        freq2[pat[i]-97]++;
	    }
	    
	    int cnt = 0;
	   
	    if(isAnagram(freq,freq2))
	    cnt++;
	    
	    for(int i=k; i<n; i++)
	    {
	        freq[txt[i]-97]++;
	        freq[txt[i-k]-97]--;
	        
	        if(isAnagram(freq,freq2))
	        cnt++;
	    }
	    
	    return cnt;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends