//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int n = str1.size(), m = str2.size();
        int mini = INT_MAX;
        int s = -1,e = -1;
        
        for(int i = 0; i<n; i++){
            
            if(str1[i] == str2[0]){
                int j = i, k = 0;
                
                while(j<n && k<m){
                    if(str1[j] == str2[k]){
                        j++;
                        k++;
                    }
                    else{
                        j++;
                    }
                }
                
                if(k != m)
                    continue;
                
                int end = j-1;
                j = j-1;
                k = m-1;
                
                while(k>=0 && j >= i){
                    if(str1[j] == str2[k]){
                        j--;
                        k--;
                    }
                    else{
                        j--;
                    }
                }
                
                int start = j+1;
                // cout<<i<<" "<<start<<" "<<end<<endl;
                if(mini > end-start+1){
                    mini = end-start+1;
                    s = start;
                    e = end;
                }
                
            }
        }
        
        if(mini == INT_MAX)
            return "";
        return str1.substr(s,e-s+1);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends