//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        vector<int> freq(26,0);
        int n = s.size();
        int i = 0, j = n-1;
        int curr = i;
        int rev = 0;
        
        for(int i = 0; i<n; i++)
            freq[s[i]-'a']++;
        
        
        while(i<j){
            if(!rev){
                if(freq[s[i]-'a'] > 1){
                    freq[s[i]-'a']--;
                    s[i] = '.';
                    rev = !rev;
                }
                i++;
            }
            else{
                if(freq[s[j]-'a'] > 1){
                    freq[s[j]-'a']--;
                    s[j] = '.';
                    rev = !rev;
                }
                
                j--;
            }
            
            
        }
        
        string ans = "";
        for(int i = 0; i<n; i++){
            if(s[i] != '.')
                ans += s[i];
        }
        
        if(rev)
            reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends