//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            int n = s.size();
            for(int i = 0; i<n; i++){
                if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
                    return false;
                
            }
            
            int j = 0;
            
            
            int f = 0;
            while(j<n && f < 4){
                string temp = "";
                if(s[j] == '.')
                    return false;
                
                while(j<n && s[j] != '.')
                    temp += s[j++];
                f++;
                if(j<n && f < 4)
                    j++;
                if(temp.size() > 3)
                    return false;
                if(temp.size() > 1 && temp[0] == '0')
                    return false;
                long long int num = stoi(temp);
                
                if(num < 0 || num >255)
                    return false;
                
            }
            
            return f == 4 && j == n ;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends