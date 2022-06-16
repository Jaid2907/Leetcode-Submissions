// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here  
        int n = s.size();
        unordered_map<char,int> mp, mp1;
        
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        
        int k = mp.size();
        int start = 0;
        int i = 0;
       
        while(k){
            if(mp1.find(s[i]) == mp1.end()){
                k--;
            }
            mp1[s[i]]++;
            
            i++;
            
             while(mp1[s[start]]>1){
             mp1[s[start]]--;
             start++;
            }
            
        }
        
        int ans = i-start;
        
        for(; i<n; i++){
            
            
            mp1[s[i]]++;
            
            while(mp1[s[start]]>1){
             mp1[s[start]]--;
             start++;
            }
            
            ans = min(ans,i-start+1);
            
        }
        
        
        
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends