//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

vector<int> vis(1e5+1,0);
vector<int> check(1e5+1,-1);

int f = 0;

class Solution{
public:
    
    
    int helper (int num, vector<int>& vis, vector<int>& check){
        
        
        if(num == 1)
            return  check[num] = num;
        if(num == 0)
            return  check[num] = -1;
        
        if(vis[num])
            return check[num];
            
        vis[num] = 1;
        int sum = 0;
        int orig = num;
        while(num){
            sum += ((num%10)*1ll*(num%10));
            num /= 10;
        }
        
        int res = helper(sum,vis,check);
        
        if(res != -1)
            return check[orig] = orig;
        return check[orig] = -1;
    }

    int nextHappy(int N){
        // code here
        if(f == 0){
            for(int i = 1e5; i>=1; i--){
            if(!vis[i]){
                helper(i,vis,check);
                }
            }
          f = 1;
        }
        for(int i = N+1; i<=1e5; i++){
            if(check[i] != -1)
                return i;
        }
        
        return 1e5;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends