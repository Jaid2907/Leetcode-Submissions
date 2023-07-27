//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.size() != B.size())
            return -1;
        
        int cnt[256] = {0};
        
        for(int i = 0; i<A.size(); i++){
            cnt[A[i]]++;
            cnt[B[i]]--;
        }
        
        for(int i = 0; i<256; i++)
            if(cnt[i] != 0)
                return -1;
        
        int n = A.size();
        int i = n-1, j = n-1;
        int res = 0;
        
        while(i>=0){
            int cnt = 0;
            while(i>=0 && A[i] != B[j]){
                cnt++;
                i--;
            }
            
            res += cnt;
            if(i >= 0){
                i--;
                j--;
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends