//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char s[], int n)
{
    //code here
    vector<vector<int>> dp(n, vector<int>(n,0));
    
    int sum = 0;
    for(int i = 0; i<n; i++)
        dp[i][i] = 1;
        
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++){
            
            if(s[i] == s[j]){
                if(dp[i+1][j-1] || j-i == 1)
                    dp[i][j] = 1;
            }
        
        sum += dp[i][j];
        }
    }
    
    return sum;
    
    
    
}