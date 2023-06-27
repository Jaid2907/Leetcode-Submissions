//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        int cnt = 0;
        for(int i = 0; i<n; i++){
            
            int l = 0;
            int m = 0;
            
            while(l<arr[i].size() && m<str.size() && m<k){
                if(arr[i][l] == str[m]){
                    l++;
                    m++;
                }
                else{
                    break;
                }
            }
            
            if(m == k){
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends