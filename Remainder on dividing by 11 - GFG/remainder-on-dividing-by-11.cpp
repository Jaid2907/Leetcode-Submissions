//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       int n = x.size();
       int sum = 0;
       int cnt = 0;
       
       for(int i = n-1; i>=0; i--){
           int num = x[i]-48;
           if(cnt%2 == 0){
               (sum += (num%11))%=11;
           }
           else{
               (sum += (num%11 * 10))%=11;
           }
           cnt++;
       }
       
       return sum;
    
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends