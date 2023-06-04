//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


void helper(int i,string& s, vector<string>& curr, vector<vector<string>>& ans, vector<vector<bool>>& dp){

    if(i == s.size()){
        if(!curr.empty())   
            ans.push_back(curr);
        return;
    }
    string temp = "";
    for(int j = i; j<s.size(); j++){
        temp += s[j];
        if(dp[i][j]){
            curr.push_back(temp);
            helper(j+1,s,curr,ans,dp);
            curr.pop_back();
        }
    }
}
class Solution {
  public:
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        // Write your code here.
    int n = s.size();
    vector<vector<string>> ans;
    vector<string> curr;
    if(n == 0)  
        return ans;
    vector<vector<bool>> dp(n+1, vector<bool>(n+1,false));

    for(int i = n-1; i>=0; i--){
        for(int j = i; j<n; j++){
            if(j-i == 0)
                dp[i][j] = true;
            else if(j-i == 1)
                dp[i][j] = s[i] == s[j];
            else{
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
            }
        }
    }
    
    helper(0,s,curr,ans,dp);
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

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends