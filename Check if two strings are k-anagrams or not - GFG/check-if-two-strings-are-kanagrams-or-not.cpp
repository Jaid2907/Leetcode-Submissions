//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        int freq[26] = {0};
        int n = str1.size(), m = str2.size();
        
        if(n != m)
            return false;
        for(int i = 0; i<n; i++)
            freq[str1[i]-'a']++;
        for(int i = 0; i<m; i++)
            freq[str2[i]-'a']--;
        
        int pos = 0, neg = 0;
        
        for(int i = 0; i<26; i++)
            if(freq[i] > 0)
                pos += freq[i];
            else
                neg += abs(freq[i]);
        
        if(pos == neg && pos <= k)
            return true;
        return false;
                
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends